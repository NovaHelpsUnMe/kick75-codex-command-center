# Kick75 Codex Command Center

NuPhy Kick75 QMK firmware and macOS runtime integration for the Codex Command Center.

This repository is the canonical home for the verified Kick75 Codex firmware, Codex and reasoning layers, KITT and task-status RGB behavior, Raw HID status delivery, macOS Status and Sidebar helpers, recovery assets, and future keyboard-side work. The separate [kick75-customizer-app](https://github.com/NovaHelpsUnMe/kick75-customizer-app) repository owns VIA definition tooling, profile parsing, keyboard visualization, and the customizer UI.

## Stable v1.0 baseline

The migrated `v1.0.0` release preserves the known-good public baseline:

- a red KITT scanner while Codex mode is active;
- F1–F4 navigation and live status colors for the first four pinned Codex tasks;
- F5–F12 Codex shortcuts;
- sidebar and reasoning knob modes;
- isolated indicator lighting for Codex controls;
- normal keyboard behavior and saved VIA settings outside Codex mode.

Live task-status delivery requires wired USB. Normal keyboard input remains available outside Codex mode through the keyboard's supported connection modes.

The current firmware source matches the September 18, 2026 physically accepted keyboard source: its Codex-mode Delete-position key sends the private Govee Edge Sync toggle chord, while normal Delete and Fn+Insert remain available outside Codex mode. See the [firmware snapshot](firmware/README.md) for source hashes and rebuild evidence. The v1.0 release remains a separate historical baseline.

Start with the [complete feature report](docs/codex-command-center.md) or the [recovery guide](docs/recovery.md). The verified source snapshot is under [firmware](firmware/README.md), the local status/sidebar bridge is under [helpers/macos](helpers/macos/README.md), and the repository split is documented in [migration provenance](docs/migration-provenance.md).

## Repository layout

```text
.
├── docs/                 # feature, recovery, roadmap, and provenance records
├── firmware/             # verified Kick75 QMK source snapshot
├── helpers/macos/        # Codex status and sidebar bridge source and tests
└── scripts/              # reproducible macOS helper build script
```

## Verification commands

```bash
python3 -m unittest helpers.macos.tests.test_codex_status
./scripts/build-macos-helpers.sh
```

Firmware target: `nuphy/kick75/ansi:via`.

## Safety and compatibility

- This is an unofficial community project and is not affiliated with NuPhy or OpenAI.
- The firmware target is **NuPhy Kick75 ANSI QMK/VIA** with USB IDs `19F5:32D5`.
- Codex desktop shortcuts and local state formats can change. Each release records the tested behavior and source revision.
- Never commit API keys, personal task databases, device identifiers, or machine-specific paths.
- Do not flash firmware intended for a different Kick75 layout or model.

## Future work

Micro Parity v2 and all roadmap items are future work, not shipped functionality. Planned work enters the feature report and changelog only after separate approval, implementation, and verification. See the [roadmap](docs/roadmap.md).

## License and attribution

The project is distributed under GPL-2.0-or-later to remain compatible with the QMK-derived firmware. See [LICENSE](LICENSE) and [third-party notices](THIRD_PARTY_NOTICES.md).

Created and maintained by [NovaHelpsUnMe](https://github.com/NovaHelpsUnMe).
