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
- [Console variants](#console-variants)

---

## HitmanBloodMoney.ini

The engine configuration file, also referred to as `MAIN.ini`. Settings use either `Key=Value` or
`Key Value` form; both appear in the shipped file and both work. Commenting a line out with `;`
disables it. For several settings, the *presence* of the key is what enables the behaviour,
regardless of any value given.

The provided copy is written for one specific scenario, **4K resolution with debug options
enabled**, and is meant to be re-configured rather than used verbatim.

### `[APPLICATION]`

Engine bootstrap: which scene loads first, where content is read from, and which input config to
use.

| Setting | Notes |
|---|---|
| `DefaultScene` | First scene the engine loads. Set to `HitmanBloodMoney.gms` (the boot menu). Can be set to any level, as each has its own `.gms` (Glacier Menu System) file. |
| `ScenesPath` | Root directory for scenes; these may be `.zip` or `.gms` files. Commented out by default. |
| `ProjectPath` | As `ScenesPath`, but for the whole game folder. |
| `streamfile` | File the engine streams audio data from, `pc_eng.str`. |
| `ConfigFile` | Controller/keyboard bindings file. Points at `HM3GPAD.cfg`. |
| `ReadMainIni` | Set to `1` to read the executable's **pre-baked** configuration, which causes this file to be ignored entirely. Keep at `0`. |
| `DisableOptions` | Disables the in-game options menu. |
| `BackColor` | Windows-only background colour, as `R,G,B`. |
| `DisableMenuTimers` | Effect not yet established. |
| `EnableNewSceneFormat` | Purpose not yet established. Commented out. |
| `BuildTag` | WARNING: uncommenting this **freezes the game on boot**. Leave commented. |

### `[CONFIGURATION]`

Blood, vibration, mouse and free-camera behaviour.

`WantBlood 1` enables blood. `NoBlood 1` disables it, but `WantBlood` takes precedence, so if
`WantBlood` is `1` then `NoBlood` is ignored.

Sub-sections: `[MOUSE]` (`UseMouse`, `MouseSpeed`) and `[FREECAM]`, where `FreeCamMode` selects
`1` for mouse or `0` for controller.

### `[GAMEPLAY]`

`AutoCrouchWhenTighteningFiberWire`, `Subtitles`, `PipCam` and `AutoAim`. All boolean.

### `[GRAPHICS OPTIONS]`

Renderer selection and display mode, plus a set of sub-sections covering detail and quality.

| Setting | Notes |
|---|---|
| `DrawDll` | Render DLL to load, `RenderD3D.dll`. |
| `StartUpperPos` | Upper-left corner of the window, as `X,Y`. |
| `Resolution` | Render resolution. Set to `3840x2160` in the provided config. |
| `ColorDepth` | Screen colour depth in bits per pixel. |
| `Antialias` | `8` = 8x AA, `4` = 4x AA, `2` = 2x AA, `0` = off. |
| `Window` | `1` starts windowed instead of fullscreen. |

**`[V-SYNC]`** holds `EnableVSync` and `EnableTripleBuffering`. Note that the shipped comment
documents `EnableVSync` as `1` = on, `2` = off, which does not follow the usual 1/0 convention
used elsewhere in the file.

**`[DEBUG RENDERING OPTIONS]`** holds `DebugVertexShader` and `DebugPixelShader`, both present but
commented out; enabling them is extremely costly to performance. `ExpandVertexBuffers` is active.

**`[LEVEL OF DETAIL]`** holds `LevelOfDetail` from `3` (high) to `0` (low), and `DrawDistance` as
a float multiplier.

**`[TEXTURES]`** holds `TextureResolution`, which runs `0` (max) to `3` (low), the inverse of most
other quality settings here. `DisableTextures` (commented out) removes background textures from
overlay menus such as pause and briefing screens. `DisableEMBM` disables environmental bump
mapping.

**`[TEXTURE FILTERING]`** holds `Anisotropy`, up to a maximum of `16`.
`DisableTrilinearFiltering` should be set to `1` when anisotropic filtering is enabled.

**`[SHADOWS]`** holds `SelfShadows`, which enables self-shadowing on 47. `ShadowDetail` selects
which objects cast shadows (`2` = all characters, `0` = nothing). `ShadowResolution` affects
**dynamic shadows only**, not pre-baked ones. Also `BlurShadows` and `DisableDropShadowBlur`.

**`[LIGHTING]`** holds `DisableLight` (commented out), which disables lighting on materials that
have dynamic shadows. `DisplayLights` is a debug option showing where lights sit in the scene.

**`[SHADERS]`** holds `DisableShaderCache`.

**`[POST PROCESSING]`** holds `PostFilterLOD` (`2` high, `0` low), `ShaderQuality`, and
`RenderUsePartialPrecisionShader`, which trades pixel-shader precision for speed on shader model
2.0 and 3.0. Note the inverted convention on the two filter toggles: for `GfxPostFilter` and
`GfxPostFilterDepthBlur`, **`0` = on and `1` = off**.

**`[FOG]`** holds `FogEnabled` and `Culling`.

### `[AUDIO]`

`SoundDll` names the sound DLL (`soundengine.dll`). `EnableDirectSound` selects the DirectX audio
implementation; `EnableDieselPower` and `EnableOpenAL` are present but commented out.

`[ENVIRONMENTAL AUDIO]` holds `UseEAX`. `[AUDIO BUFFER]` holds `NumSoundBuffers`, maximum `64`.
`[VOLUME CONTROLLERS]` holds per-channel float volumes for SFX, dialog, music, ambience and
movies. `[DEBUG]` holds `PrintSoundMapping`.

### `[SCRIPT]`

`ScriptDebug`, `ScriptEnableSanityCheck` and `EnableScriptRTC` control script debugging.
`ScriptDebugPrint` allows scripts to print to `zDebug`, though this may be disabled depending on
the build. `DisableScripts` still allows the game to be played, with, as the shipped comment puts
it, some interesting effects. `ScriptIfDll` and `ScriptDll` are present but commented out.

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
| `&` | AND. All operands must be active. Chains as `& &` for three operands. |
| `\|` | OR. Either operand triggers the action. |
| `!` | NOT. Negates the operand that follows. |
| `-` | Opposes two operands on one axis, giving negative and positive directions. |

So `ToggleDebugDisplay=& & tap(kb,f9) hold(kb,lshift) hold(kb,lctrl);` binds Ctrl+Shift+F9, and
`MoveX=-hold(kb,right) hold(kb,left);` makes Left and Right the two directions of one axis.

### Blocks

| Block | Purpose |
|---|---|
| `ccc=` | Core camera and movement: mouse look, analogue sticks, turbo. |
| `CutSequence`, `CutSequence2` | Skipping cutscenes. |
| `Video` | Skipping full-motion video. |
| `DeathSequenceInput` | Ending the death sequence. |
| `HMControl` | Main gameplay bindings: inventory, weapon cycling, action and pickup menus, slow motion, map and briefing. |
| `IngameMap` | In-game map navigation. |
| `WEAPONDETAILS_1` | Weapon inspection view: pan, rotate, zoom. |
| `StatisticsTestActions` | Statistics screen navigation. |
| `PushScene` | Scene push (`start`). |
| `EditPostfilter` | Post-filter debugging views: bloom, z-buffer alpha, finish alpha. |
| `PlayerTestControl` | Developer player-movement test bindings on the numpad. |
| `Debug` | Cheat and debug actions, see below. |
| `DebugKeys` | Debug display toggles, see below. |
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

**`DebugKeys` does not work in the retail release of the game**, and the other debug blocks may
be affected in the same way.

To use a `DebugKeys` binding such as free camera on a retail build, move it into the
`ZWINDOWSKEYS_1` block instead, which is still processed.

Note also that this only covers the *bindings*. The features themselves are gated by
`EnableDebugOptions`, `EnableConsole` and `EnableCheats` in the `[DEBUG]` section of the `.ini`,
and on retail builds `EnableCheats` is additionally enforced in the executable, which is what
[cheat-enabler](../tools/cheat-enabler/) works around by writing the flag directly into the
running process.

---

## Console variants

The console releases use the same two-file arrangement with different names and much smaller
contents. The following was read from the Xbox 360 review build disc listed in
[releases.md](releases.md#all-known-builds), where the files sit in the disc root as `main.ini`
and `hmbgpad.cfg`.

The Xbox 360 `main.ini` is 63 bytes in total:

```
DefaultScene=hitmanbloodmoney.gms
ConfigFile=hmbgpad.cfg
```

Everything the PC `.ini` exposes as tunable is baked into the executable on console. Only the two
bootstrap keys remain, which is exactly what `ReadMainIni 1` does on PC.

The Xbox 360 `hmbgpad.cfg` is around 2.3 KB against the PC file's 4.7 KB, and differs in
structure as well as size:

- Only three blocks are present: `ZWINDOWSKEYS_1`, `HMControl` and `DeathSequenceInput`. The PC
  file has fifteen.
- There are no `Debug`, `DebugKeys` or `DebugAlways` blocks at all, so the debug bindings
  documented above have no console equivalent.
- Every binding uses the `gc` device. There are no `kb` or `ms` bindings.
- Control names are the Xbox 360 set: `dpad_up`, `left_trigger`, `right_shoulder`, `left_thumb`,
  `back`, `start`, and the face buttons `a`, `b`, `x`, `y`.
- `HMControl` opens with `UseGameController = true;`, and absorbs the map, statistics, video and
  cut-sequence actions that are separate blocks on PC.

One debug binding does survive on console, in `HMControl`:

```
CheatsMenuGC=&&hold(gc,right_trigger) hold(gc,right_thumb) hold(gc,left_trigger);
```

That is right trigger plus right thumbstick plus left trigger held together, the console
counterpart of the PC `CheatsMenuGC` binding on `p`.

### Xbox

Read from the demo on *Official Xbox Magazine* Game Disc 57 (build `21662`), where the files sit
under `HitmanBloodmoney/` as `main.ini` and `hmbgpad.cfg`.

The Xbox `main.ini` is 205 bytes, and unlike the other two consoles it exposes real tunables:

```
DefaultScene=HitmanBloodMoney.gms
ConfigFile=hmbgpad.cfg
UseGameController
GammaValue 1.0
MouseSpeedX 0.7
MouseSpeedY 0.7
SoundBuffers 64
DisableOptions
AUDIO_HighQualityResampling
BuildTag Demo
```

Points of interest:

- `BuildTag Demo` again, as on PS2. Two independent console builds carry it, which further
  supports the reading that the key is functional and only the PC retail executable objects.
- `MouseSpeedX` and `MouseSpeedY` are present on a console with no mouse, and are split into two
  axes where the PC file has a single `MouseSpeed`. Leftovers from the PC codebase.
- `DefaultScene` is `HitmanBloodMoney.gms`, matching the PC rather than the PS2 demo's
  `bootmenu.gms`.
- `AUDIO_HighQualityResampling` and `SoundBuffers` appear here as bare top-level keys rather than
  inside the `[AUDIO]` section the PC file uses; the console files have no section headings at all.

The Xbox `hmbgpad.cfg` is 2,325 bytes with the same three blocks as the other consoles. Its
control names are the original Xbox set: `a`, `b`, `x`, `y`, `black`, `left_trigger`,
`right_trigger`, `left_thumb`, `right_thumb`, `back`, `start` and `dpad_*`.

The clearest generational marker is `ReloadWeapon=tap(gc,black);`, bound to the original Xbox
controller's Black button, which has no equivalent on the Xbox 360 pad. The Xbox 360 file binds
the same action to `right_shoulder`.

### PlayStation 2

Read from the PS2 magazine demo disc `SCED_54044` (build `22981`, see
[releases.md](releases.md#all-known-builds)), where the same two files sit under `HITMAN/` as
`MAIN.INI` and `HM3GPAD.CFG`.

The PS2 `MAIN.INI` is 166 bytes:

```
ProjectPath host0:
DefaultScene=bootmenu.gms
ConfigFile=hm3gpad.cfg

ConsoleCmd show_debuggeoms 0
ConsoleCmd show_debug 0

BuildTag Demo
PS2VideoConfigPAL 1
```

Four things are worth drawing out of that:

- **`BuildTag` is genuinely used, and holds a build-variant name.** The PC file documents this
  setting as one that freezes the game on boot if uncommented, so its purpose was unclear. Here
  it is active with the value `Demo`. The setting works; what the retail PC executable rejects is
  presumably the value, not the key.
- **`ProjectPath host0:`** points at the PS2 development kit's host filesystem, which is the
  path a build machine would load from. It shipped on pressed retail media unchanged.
- **`DefaultScene=bootmenu.gms`**, where the PC file boots `HitmanBloodMoney.gms`. The demo
  disc carries a matching `SCENES/BOOTMENU.*` scene set.
- The two `ConsoleCmd` debug lines are present but explicitly set to `0`, rather than being
  commented out or absent.

Note also the boot chain. The disc's `SYSTEM.CNF` reads:

```
BOOT2=cdrom0:\SCED_540.44;1
VER=1.00
VMODE=PAL
```

`SCED_540.44` is the magazine's multi-game front-end, which then launches
`HITMAN/HITMAN.ELF`; the game's own configuration is not consulted until that point.

The PS2 `HM3GPAD.CFG` is 2,302 bytes and has the same three-block structure as the Xbox 360 file
above, `ZWINDOWSKEYS_1`, `HMControl` and `DeathSequenceInput`, with no debug blocks. Only the
control names differ, using the PlayStation set: `cross`, `circle`, `triangle`, `square`,
`left1`, `right1`, `left2`, `right2`, `leftstick`, `rightstick`, `start` and `select`.

Its cheat binding is:

```
CheatsMenuGC=&& hold(gc,right1) hold(gc,right2) tap(gc,up);
```

R1 plus R2 held with Up tapped. So all three platforms retain a controller cheat-menu chord, on
different inputs.
