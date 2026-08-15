# Hitman: Blood Money - Cheat Enabler

Unlocks the in-game cheat menu on retail builds of *Hitman: Blood Money*.

Retail builds ship with the engine's `EnableCheats` flag forced off, so setting `EnableCheats 1`
in `HitmanBloodMoney.ini` is not enough on its own. This tool attaches to the running game and
writes the flag directly into process memory, re-asserting it once per second so it stays set.

## Credits

- Original enabler by **ZoID** — <http://forums.eidosgames.com/showthread.php?t=61298>
- Improved and fixed for Steam by **RDJ** — <http://roguedarkjedi.com>

Reported by the program itself as *"Cheat Menu enabler V1.12"*. See
[Third-party components](../README.md#third-party-components) regarding licensing.

## Usage

**Start the game first.** The tool locates the game by window title (`Hitman` or
`Hitman Blood Money`) and exits with an error if no such window is open.

1. Launch *Hitman: Blood Money* and leave it running.
2. Run the enabler.
3. Choose your version when prompted — `1` for Steam, `2` for original CD retail.
4. Once you are in gameplay, press **`C`** to open the cheat console.

Leave the tool running while you play. It polls the game every second and will report if the
process goes away.

## Version addresses

The flag lives at a different address depending on the build, which is why the version prompt
exists:

| Version | `g_bEnableCheats` address |
|---|---|
| Steam | `0x8ABA89` |
| Original CD retail | `0x8ACA89` |

If neither works, your build is a different one from the two this tool knows about — see
[releases.md](../../docs/releases.md) for the catalogue of known builds.

## Building

Source only; no binary is included. It is a single file with no dependencies beyond the Windows
SDK, and targets Windows XP or later.

```
cl /EHsc src\hbm_cheatenabler.cpp User32.lib
```

or with MinGW:

```
g++ -o hbm_cheatenabler.exe src/hbm_cheatenabler.cpp -luser32
```

## Notes

The tool needs `PROCESS_ALL_ACCESS` on the game process, so it may require running as
administrator, and writing to another process's memory will look like tampering to some
anti-virus software.

Related: `EnableCheats` and the other debug switches are documented in the
[configuration reference](../../docs/config-reference.md#debug), and the cheat menu key binding
itself (`CheatsMenu=fasttap(kb,c)`) lives in
[`HM3GPAD.cfg`](../../config/HM3GPAD.cfg).
