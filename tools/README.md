# Tools

Open-source tools published for *Hitman: Blood Money*, collected here so they stay findable.

| Tool | What it does | Original author |
|---|---|---|
| [cheat-enabler](cheat-enabler/) | Unlocks the in-game cheat menu on retail builds by setting the engine's `EnableCheats` flag in the running process. | [ZoID](http://forums.eidosgames.com/showthread.php?t=61298), fixed for Steam by [RDJ](http://roguedarkjedi.com) |
| [prm-converter](prm-converter/) | Dumps PRM archives — the Glacier engine's model container — to Wavefront OBJ. | John "Cryect" Rittenhouse |

## Third-party components

**The tools in this directory were not written by this repository's maintainer.** Each is the
work of its original author, credited above and in its own README, and is included here under the
terms under which it was originally published. Copyright remains with the respective authors.

The [`LICENSE`](../LICENSE) at the root of this repository covers the documentation and
configuration files authored here — it does **not** apply to the contents of this directory.

If you are an author of one of these tools and would like the terms clarified, corrected or the
code removed, please open an issue.

## Building

Both tools are single-file C++ programs with no dependencies beyond the platform SDK. Per-tool
build commands are in each tool's README.

`prm-converter` additionally ships a prebuilt Windows binary from the original author, in
[`prm-converter/bin/`](prm-converter/bin/).
