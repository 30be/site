import { QuartzFilterPlugin } from "../types"
import { readFileSync } from "fs"
import { join } from "path"

export const NewNoteWarning: QuartzFilterPlugin = () => ({
    name: "NewNoteWarning",
    shouldPublish(_ctx, [_tree, vfile]) {
        const notesFilePath = join(process.cwd(), "notes.txt")
        try {
            const notesContent = readFileSync(notesFilePath, "utf-8")
            const noteNames = notesContent.split("\n").map(name => name.trim())
            if (noteNames.includes(vfile.data.filePath!.split("/").pop()!))
                return true
            console.log(`New note: ${vfile.data.filePath!.split("/").pop()}`)
            return false
        } catch (error) {
            console.warn("Could not read notes.txt:", error)
            return true
        }
    },
})
