import { QuartzFilterPlugin } from "../types"

export const ExplicitPublish: QuartzFilterPlugin = () => ({
  name: "ExplicitPublish",
  shouldPublish(_ctx, [_tree, vfile]) {
    return vfile.data?.frontmatter?.public === true || vfile.data?.frontmatter?.public === "true"
  },
})
