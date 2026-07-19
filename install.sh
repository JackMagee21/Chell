#!/usr/bin/env bash
# Installs Chell as a launchable desktop application.
#
# What this does:
#   1. Confirms the binary is built.
#   2. Writes a .desktop launcher file with an absolute path to the binary.
#   3. Installs it to ~/.local/share/applications (shows up in your app
#      menu / launcher — GNOME Activities, KDE Kickoff, etc.)
#   4. Optionally drops a copy on your Desktop, marked as trusted/executable
#      so it's directly double-clickable from the file manager.
#
# Safe to re-run; it just overwrites the generated .desktop file.

set -euo pipefail

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BINARY="$DIR/main"
DESKTOP_FILE="chell.desktop"
APPS_DIR="$HOME/.local/share/applications"

if [[ ! -x "$BINARY" ]]; then
    echo "Error: $BINARY not found or not executable. Run 'make' first." >&2
    exit 1
fi

mkdir -p "$APPS_DIR"

cat > "$APPS_DIR/$DESKTOP_FILE" <<EOF
[Desktop Entry]
Type=Application
Name=Chell
Comment=A simple custom command shell
Exec=$BINARY
Icon=utilities-terminal
Terminal=true
Categories=Utility;System;
EOF

chmod +x "$APPS_DIR/$DESKTOP_FILE"
echo "Installed launcher to: $APPS_DIR/$DESKTOP_FILE"
echo "It should now appear in your application menu as 'Chell'."

# Optional: also place a launcher on the Desktop for direct double-click
if [[ -d "$HOME/Desktop" ]]; then
    cp "$APPS_DIR/$DESKTOP_FILE" "$HOME/Desktop/$DESKTOP_FILE"
    chmod +x "$HOME/Desktop/$DESKTOP_FILE"

    # GNOME's Nautilus requires files to be marked "trusted" before it will
    # execute them directly on double-click, otherwise it just opens them
    # as text or shows a warning dialog. gio is part of glib2 and present
    # on virtually all GNOME systems by default.
    if command -v gio >/dev/null 2>&1; then
        gio set "$HOME/Desktop/$DESKTOP_FILE" metadata::trusted true 2>/dev/null || true
    fi

    echo "Also placed a launcher on your Desktop: $HOME/Desktop/$DESKTOP_FILE"
    echo "If double-clicking it doesn't run immediately, right-click it and choose 'Allow Launching' (GNOME) or 'Trust and Launch' (KDE) once."
fi