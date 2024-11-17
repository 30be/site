import express from 'express'
import serveIndex from 'serve-index'
const app = express()
const port = 80

app.use(express.static('public', { extensions: ['html'] }))
app.use("/MultiEditor", express.static('MultiEditor/output', { extensions: ['html'] }))

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})

express()
    .use(express.static('shared'), serveIndex('shared', { icons: true }))
    .listen(3000)
