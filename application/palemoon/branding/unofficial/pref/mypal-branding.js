#filter substitution
#filter emptyLines
#include ../../shared/pref/preferences.inc
#include ../../shared/pref/uaoverrides.inc

pref("startup.homepage_override_url","https://feodor2.github.io/Mypal/");
pref("app.releaseNotesURL", "https://github.com/Feodor2/Mypal/releases");

// Enable Firefox compatmode by default.
pref("general.useragent.compatMode", 2);
pref("general.useragent.compatMode.gecko", true);
pref("general.useragent.compatMode.firefox", true);

// Updates disabled
pref("app.update.enabled", false);
pref("app.update.url", "https://raw.githubusercontent.com/Feodor2/Updserv/master/%PRODUCT%/%BUILD_TARGET%/%LOCALE%/update.xml");
