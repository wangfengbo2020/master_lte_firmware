// Auto-generated version header
// This file is generated during build by Makefile

#ifndef VERSION_H
#define VERSION_H

// Git version (from git describe --tags)
// Examples:
//   v1.0.0              - exact tag
//   v1.0.0-5-g745cc1e   - 5 commits after v1.0.0 tag
//   v1.0.0-dirty        - uncommitted changes
//   745cc1e             - no tags, shows commit hash
#ifndef GIT_VERSION
#define GIT_VERSION "unknown"
#endif

// Git commit date
#ifndef GIT_COMMIT_DATE
#define GIT_COMMIT_DATE "unknown"
#endif

// Git branch name
#ifndef GIT_BRANCH
#define GIT_BRANCH "unknown"
#endif

// Build date and time
#ifndef BUILD_DATE
#define BUILD_DATE __DATE__ " " __TIME__
#endif

// Full version string
#define VERSION_STRING GIT_VERSION " (" GIT_COMMIT_DATE ")"

#endif // VERSION_H
