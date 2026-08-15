# Configuration Reference

Reference for the two configuration files the Glacier engine reads at startup:
[`HitmanBloodMoney.ini`](../config/HitmanBloodMoney.ini) (engine settings) and
[`HM3GPAD.cfg`](../config/HM3GPAD.cfg) (input bindings).

The copies in [`config/`](../config/) are formatted, commented and hand-written versions of files
that shipped undocumented. This page explains what the sections do; the files themselves carry
per-setting comments inline.

- [HitmanBloodMoney.ini](#hitmanbloodmoneyini)
- [HM3GPAD.cfg](#hm3gpadcfg)
- [Enabling the debug features](#enabling-the-debug-features)

---

## HitmanBloodMoney.ini

The engine configuration file, also referred to as `MAIN.ini`. Settings use either `Key=Value` or
`Key Value` form; both appear in the shipped file and both work. Commenting a line out with `;`
disables it — for several settings, the *presence* of the key is what enables the behaviour,
regardless of any value given.

The provided copy is written for one specific scenario — **4K resolution with debug options
enabled** — and is meant to be re-configured rather than used verbatim.

### `[APPLICATION]`

Engine bootstrap: which scene loads first, where content is read from, and which input config to
use.

| Setting | Notes |
|---|---|
| `DefaultScene` | First scene the engine loads. Set to `HitmanBloodMoney.gms` (the boot menu). Can be set to any level, as each has its own `.gms` (Glacier Menu System) file. |
| `ScenesPath` | Root directory for scenes; these may be `.zip` or `.gms` files. Commented out by default. |
| `ProjectPath` | As `ScenesPath`, but for the whole game folder. |
| `streamfile` | File the engine streams audio data from — `pc_eng.str`. |
| `ConfigFile` | Controller/keyboard bindings file. Points at `HM3GPAD.cfg`. |
| `ReadMainIni` | Set to `1` to read the executable's **pre-baked** configuration, which causes this file to be ignored entirely. Keep at `0`. |
| `DisableOptions` | Disables the in-game options menu. |
| `BackColor` | Windows-only background colour, as `R,G,B`. |
| `DisableMenuTimers` | Effect not yet established. |
| `EnableNewSceneFormat` | Purpose not yet established. Commented out. |
| `BuildTag` | ⚠️ Uncommenting this **freezes the game on boot**. Leave commented. |

### `[CONFIGURATION]`

Blood, vibration, mouse and free-camera behaviour.

`WantBlood 1` enables blood. `NoBlood 1` disables it — but `WantBlood` takes precedence, so if
`WantBlood` is `1` then `NoBlood` is ignored.

Sub-sections: `[MOUSE]` (`UseMouse`, `MouseSpeed`) and `[FREECAM]`, where `FreeCamMode` selects
`1` = mouse or `0` = controller.

### `[GAMEPLAY]`

`AutoCrouchWhenTighteningFiberWire`, `Subtitles`, `PipCam` and `AutoAim`. All boolean.

### `[GRAPHICS OPTIONS]`

Renderer selection and display mode, plus a set of sub-sections covering detail and quality.

| Setting | Notes |
|---|---|
| `DrawDll` | Render DLL to load — `RenderD3D.dll`. |
| `StartUpperPos` | Upper-left corner of the window, as `X,Y`. |
| `Resolution` | Render resolution. Set to `3840x2160` in the provided config. |
| `ColorDepth` | Screen colour depth in bits per pixel. |
| `Antialias` | `8` = 8×AA, `4` = 4×AA, `2` = 2×AA, `0` = off. |
| `Window` | `1` starts windowed instead of fullscreen. |

**`[V-SYNC]`** — `EnableVSync` and `EnableTripleBuffering`. Note that the shipped comment
documents `EnableVSync` as `1` = on, `2` = off, which does not follow the usual 1/0 convention
used elsewhere in the file.

**`[DEBUG RENDERING OPTIONS]`** — `DebugVertexShader` and `DebugPixelShader` are present but
commented out; enabling them is extremely costly to performance. `ExpandVertexBuffers` is active.

**`[LEVEL OF DETAIL]`** — `LevelOfDetail` from `3` (high) to `0` (low), and `DrawDistance` as a
float multiplier.

**`[TEXTURES]`** — `TextureResolution` runs `0` (max) to `3` (low), the inverse of most other
quality settings here. `DisableTextures` (commented out) removes background textures from overlay
menus such as pause and briefing screens. `DisableEMBM` disables environmental bump mapping.

**`[TEXTURE FILTERING]`** — `Anisotropy` up to a maximum of `16`.
`DisableTrilinearFiltering` should be set to `1` when anisotropic filtering is enabled.

**`[SHADOWS]`** — `SelfShadows` enables self-shadowing on 47. `ShadowDetail` selects which
objects cast shadows (`2` = all characters, `0` = nothing). `ShadowResolution` affects **dynamic
shadows only**, not pre-baked ones. Also `BlurShadows` and `DisableDropShadowBlur`.

**`[LIGHTING]`** — `DisableLight` (commented out) disables lighting on materials that have
dynamic shadows. `DisplayLights` is a debug option showing where lights sit in the scene.

**`[SHADERS]`** — `DisableShaderCache`.

**`[POST PROCESSING]`** — `PostFilterLOD` (`2` high, `0` low), `ShaderQuality`, and
`RenderUsePartialPrecisionShader`, which trades pixel-shader precision for speed on shader model
2.0 and 3.0. Note the inverted convention on the two filter toggles: for `GfxPostFilter` and
`GfxPostFilterDepthBlur`, **`0` = on and `1` = off**.

**`[FOG]`** — `FogEnabled` and `Culling`.

### `[AUDIO]`

`SoundDll` names the sound DLL (`soundengine.dll`). `EnableDirectSound` selects the DirectX audio
implementation; `EnableDieselPower` and `EnableOpenAL` are present but commented out.

`[ENVIRONMENTAL AUDIO]` holds `UseEAX`. `[AUDIO BUFFER]` holds `NumSoundBuffers`, maximum `64`.
`[VOLUME CONTROLLERS]` holds per-channel float volumes for SFX, dialog, music, ambience and
movies. `[DEBUG]` holds `PrintSoundMapping`.

### `[SCRIPT]`

`ScriptDebug`, `ScriptEnableSanityCheck` and `EnableScriptRTC` control script debugging.
`ScriptDebugPrint` allows scripts to print to `zDebug`, though this may be disabled depending on
the build. `DisableScripts` still allows the game to be played, with — as the shipped comment puts
it — some interesting effects. `ScriptIfDll` and `ScriptDll` are present but commented out.

### `[DEBUG]`

The switches that turn on the developer features. See
[Enabling the debug features](#enabling-the-debug-features) for the caveat.

| Setting | Notes |
|---|---|
| `EnableDebugOptions` | Master switch for debug options. |
| `EnableConsole` | Enables the in-game console. |
| `EnableCheats` | Enables cheats. See also [cheat-enabler](../tools/cheat-enabler/), which sets this in memory on retail builds. |
| `enablecontrollerdebugkeys` | Enables the debug key bindings, which are defined in `HM3GPAD.cfg`. |
| `DebugMenus` | Makes debug menus reachable from the main menu. |
| `DisplayMemory` | On-screen memory display. |
| `DebugAnimPack` | Animation pack debugging. |

### `[Console Commands]` and `[Console Commands - DEBUG]`

Each `ConsoleCmd` line runs a console command at startup. The debug set enables
`show_debugtext`, `show_debuggeoms`, `show_debug` and `ActorDebugInfo`. The general set enables
`ShowVision`, `ActorInfo`, `ScriptInfo` and `ScriptFlightRecorder`, with
`ScriptFlightRecorderFile` naming the log file (`scriptlog.txt`).

---

## HM3GPAD.cfg

The controller and keyboard binding file, named by `ConfigFile` in the `.ini`. It uses a nested
block syntax rather than INI sections:

```
BlockName={
    ActionName=expression;
};
```

### Binding expression syntax

A binding is built from device functions combined by prefix operators.

**Device functions** take a device and a control: `tap(kb,esc)`, `hold(gc,right1)`,
`ana(gc0,leftx)`, `rel(ms,x)`.

| Device | Meaning |
|---|---|
| `kb` | Keyboard |
| `ms` | Mouse |
| `gc` | Game controller |
| `gc0`, `gc1` | Specific controller index |

| Function | Triggers on |
|---|---|
| `tap` | A press |
| `fasttap` | A quick press, distinguished from a hold |
| `hold` | The control being held |
| `holddown` | The moment holding begins |
| `release` | The control being released |
| `ana` | An analogue axis |
| `rel` | Relative movement, used for mouse axes |

**Combining operators** are written as a prefix before the operands:

| Operator | Meaning |
|---|---|
| `&` | AND — all operands must be active. Chains as `& &` for three operands. |
| `\|` | OR — either operand triggers the action. |
| `!` | NOT — negates the operand that follows. |
| `-` | Opposes two operands on one axis, giving negative and positive directions. |

So `ToggleDebugDisplay=& & tap(kb,f9) hold(kb,lshift) hold(kb,lctrl);` binds Ctrl+Shift+F9, and
`MoveX=-hold(kb,right) hold(kb,left);` makes Left and Right the two directions of one axis.

### Blocks

| Block | Purpose |
|---|---|
| `ccc=` | Core camera and movement — mouse look, analogue sticks, turbo. |
| `CutSequence`, `CutSequence2` | Skipping cutscenes. |
| `Video` | Skipping full-motion video. |
| `DeathSequenceInput` | Ending the death sequence. |
| `HMControl` | Main gameplay bindings — inventory, weapon cycling, action and pickup menus, slow motion, map and briefing. |
| `IngameMap` | In-game map navigation. |
| `WEAPONDETAILS_1` | Weapon inspection view — pan, rotate, zoom. |
| `StatisticsTestActions` | Statistics screen navigation. |
| `PushScene` | Scene push (`start`). |
| `EditPostfilter` | Post-filter debugging views — bloom, z-buffer alpha, finish alpha. |
| `PlayerTestControl` | Developer player-movement test bindings on the numpad. |
| `Debug` | Cheat and debug actions — see below. |
| `DebugKeys` | Debug display toggles — see below. |
| `DebugAlways` | Free-camera movement, speed control, spawning, variant cycling. |
| `ZWINDOWSKEYS_1` | Windowed-mode UI navigation keys. |

### Notable debug bindings

From the `Debug` block: `CheatsMenu=fasttap(kb,c)` opens the cheat menu, with `CheatsMenuGC` on
`p`. `InstantKill` and `Explode` are bound to Shift+F11 and Shift+F12, with right-shift variants.
`CompleteLevel` is Shift+C, `FailLevel` is Shift+F, and `ShootAtEverything` is Shift+L.

From `DebugKeys`: `ToggleFreeCam` on `k`, `ToggleTexture` on `t`, `ToggleGates` on `y`,
`ToggleAlignment` on `v`, quick save and load on Ctrl+S and Ctrl+L, plus Shift+F3/F6/F7/F8 for
the sound, light, camera and grid displays.

---

## Enabling the debug features

⚠️ **`DebugKeys` does not work in the retail release of the game**, and the other debug blocks may
be affected in the same way.

To use a `DebugKeys` binding such as free camera on a retail build, move it into the
`ZWINDOWSKEYS_1` block instead, which is still processed.

Note also that this only covers the *bindings*. The features themselves are gated by
`EnableDebugOptions`, `EnableConsole` and `EnableCheats` in the `[DEBUG]` section of the `.ini`,
and on retail builds `EnableCheats` is additionally enforced in the executable — which is what
[cheat-enabler](../tools/cheat-enabler/) works around by writing the flag directly into the
running process.
