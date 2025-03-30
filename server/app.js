import express from 'express';
import serveIndex from 'serve-index';
import { createProxyMiddleware } from 'http-proxy-middleware';
import basicAuth from 'basic-auth';

const port = 80;

express()
    .get('/i/*', (req, res) => { res.redirect(`/8080/i/${req.params[0]}`); })
    .use('/8080', createProxyMiddleware({
      target: 'http://localhost:8080',
      changeOrigin: true,              // Ensures the host header matches the target
      pathRewrite: { '^/8080': '' }    // Strips /8080, ensuring /8080/i/ -> /i/
    }))
    .use('/shared', serveIndex('public/shared', { icons: true }))
    .use('/feeds', express.static('public/shared/rss/feeds'), serveIndex('public/shared/rss/feeds', { icons: true }))
    .use('/', express.static('public'))
    .listen(port, () => {
        console.log(`Example app listening on port ${port}`);
    });
