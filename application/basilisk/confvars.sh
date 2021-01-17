#! /bin/sh
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

MOZ_APP_BASENAME=Centaury
MOZ_APP_VENDOR=Moonchild
MOZ_PHOENIX=1
MOZ_AUSTRALIS=1
MC_BASILISK=1
MOZ_UPDATER=

if test "$OS_ARCH" = "WINNT" -o \
        "$OS_ARCH" = "Linux"; then
  MOZ_BUNDLED_FONTS=1
fi

MOZ_APP_VERSION=52.9.`date --utc '+%Y.%m.%d'`
MOZ_APP_VERSION_DISPLAY=`date --utc '+%Y.%m.%d'`

MOZ_EXTENSIONS_DEFAULT=" gio"

# MOZ_APP_DISPLAYNAME will be set by branding/configure.sh
# MOZ_BRANDING_DIRECTORY is the default branding directory used when none is
# specified. It should never point to the "official" branding directory.
MOZ_BRANDING_DIRECTORY=$MOZ_BUILD_APP/branding/unofficial
MOZ_OFFICIAL_BRANDING_DIRECTORY=$MOZ_BUILD_APP/branding/official
MOZ_APP_ID={ec8030f7-c20a-464f-9b0e-13a3a9e97384}
# This should usually be the same as the value MAR_CHANNEL_ID.
# If more than one ID is needed, then you should use a comma separated list
# of values.
ACCEPTED_MAR_CHANNEL_IDS=unofficial,unstable,release
# The MAR_CHANNEL_ID must not contain the following 3 characters: ",\t "
MAR_CHANNEL_ID=unofficial

# Features
MOZ_PROFILE_MIGRATOR=1
MOZ_APP_STATIC_INI=1
MOZ_WEBGL_CONFORMANT=1
MOZ_JSDOWNLOADS=1
MOZ_WEBRTC=1
MOZ_WEBEXTENSIONS=1
MOZ_DEVTOOLS=1
MOZ_SERVICES_COMMON=1
MOZ_SERVICES_SYNC=1
MOZ_SERVICES_HEALTHREPORT=
MOZ_SAFE_BROWSING=
MOZ_GAMEPAD=1
MOZ_AV1=1
MOZ_SECURITY_SQLSTORE=1
NSS_DISABLE_DBM=1

if test "$OS_ARCH" = "WINNT" -o \
        "$OS_ARCH" = "Darwin"; then
  MOZ_CAN_DRAW_IN_TITLEBAR=1
fi

# Set the chrome packing format
# Possible values are omni, jar, and flat
# Currently, only omni and flat are supported
MOZ_CHROME_FILE_FORMAT=omni
JAR_COMPRESSION=brotli
