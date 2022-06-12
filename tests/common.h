#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "../src/cstring.h"
#include "../src/cstring_internal.h"

#define GET_TEST_ASSET(path) \
    "./tests/test_assets/" path

static const char *bytes_1024 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus eu egestas nibh. Duis vestibulum, ligula at efficitur sagittis, nulla magna finibus ex, a faucibus ipsum quam vel nibh. Donec nec sollicitudin magna. Aliquam consectetur tellus ante, a placerat libero tempus at. Donec in tristique mauris, sed ornare odio. Nulla gravida orci eget ullamcorper aliquam. Maecenas ut purus vel mauris efficitur porttitor eget eu ante. Nulla elit urna, sollicitudin vel quam vitae, rutrum mollis ipsum. Vivamus condimentum aliquam viverra. Maecenas suscipit pharetra tortor efficitur tempor. Sed ut ullamcorper quam, non vulputate sapien. Suspendisse malesuada felis a accumsan dapibus.Ut at feugiat eros, ac eleifend erat. Aenean rhoncus diam et est vehicula, vel finibus mi imperdiet. Nulla gravida urna erat, et vulputate enim bibendum et. Mauris commodo pulvinar blandit. Duis placerat tortor ut diam convallis, at fringilla diam tristique. Etiam viverra interdum urna, vitae porta mauris blandit vitae. Etiam massa mauris non.";
static const char *bytes_2048 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus eu egestas nibh. Duis vestibulum, ligula at efficitur sagittis, nulla magna finibus ex, a faucibus ipsum quam vel nibh. Donec nec sollicitudin magna. Aliquam consectetur tellus ante, a placerat libero tempus at. Donec in tristique mauris, sed ornare odio. Nulla gravida orci eget ullamcorper aliquam. Maecenas ut purus vel mauris efficitur porttitor eget eu ante. Nulla elit urna, sollicitudin vel quam vitae, rutrum mollis ipsum. Vivamus condimentum aliquam viverra. Maecenas suscipit pharetra tortor efficitur tempor. Sed ut ullamcorper quam, non vulputate sapien. Suspendisse malesuada felis a accumsan dapibus.Ut at feugiat eros, ac eleifend erat. Aenean rhoncus diam et est vehicula, vel finibus mi imperdiet. Nulla gravida urna erat, et vulputate enim bibendum et. Mauris commodo pulvinar blandit. Duis placerat tortor ut diam convallis, at fringilla diam tristique. Etiam viverra interdum urna, vitae porta mauris blandit vitae. Etiam massa mauris non.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus eu egestas nibh. Duis vestibulum, ligula at efficitur sagittis, nulla magna finibus ex, a faucibus ipsum quam vel nibh. Donec nec sollicitudin magna. Aliquam consectetur tellus ante, a placerat libero tempus at. Donec in tristique mauris, sed ornare odio. Nulla gravida orci eget ullamcorper aliquam. Maecenas ut purus vel mauris efficitur porttitor eget eu ante. Nulla elit urna, sollicitudin vel quam vitae, rutrum mollis ipsum. Vivamus condimentum aliquam viverra. Maecenas suscipit pharetra tortor efficitur tempor. Sed ut ullamcorper quam, non vulputate sapien. Suspendisse malesuada felis a accumsan dapibus.Ut at feugiat eros, ac eleifend erat. Aenean rhoncus diam et est vehicula, vel finibus mi imperdiet. Nulla gravida urna erat, et vulputate enim bibendum et. Mauris commodo pulvinar blandit. Duis placerat tortor ut diam convallis, at fringilla diam tristique. Etiam viverra interdum urna, vitae porta mauris blandit vitae. Etiam massa mauris non.";
static const char *bytes_4096 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus eu egestas nibh. Duis vestibulum, ligula at efficitur sagittis, nulla magna finibus ex, a faucibus ipsum quam vel nibh. Donec nec sollicitudin magna. Aliquam consectetur tellus ante, a placerat libero tempus at. Donec in tristique mauris, sed ornare odio. Nulla gravida orci eget ullamcorper aliquam. Maecenas ut purus vel mauris efficitur porttitor eget eu ante. Nulla elit urna, sollicitudin vel quam vitae, rutrum mollis ipsum. Vivamus condimentum aliquam viverra. Maecenas suscipit pharetra tortor efficitur tempor. Sed ut ullamcorper quam, non vulputate sapien. Suspendisse malesuada felis a accumsan dapibus.Ut at feugiat eros, ac eleifend erat. Aenean rhoncus diam et est vehicula, vel finibus mi imperdiet. Nulla gravida urna erat, et vulputate enim bibendum et. Mauris commodo pulvinar blandit. Duis placerat tortor ut diam convallis, at fringilla diam tristique. Etiam viverra interdum urna, vitae porta mauris blandit vitae. Etiam massa mauris non.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus eu egestas nibh. Duis vestibulum, ligula at efficitur sagittis, nulla magna finibus ex, a faucibus ipsum quam vel nibh. Donec nec sollicitudin magna. Aliquam consectetur tellus ante, a placerat libero tempus at. Donec in tristique mauris, sed ornare odio. Nulla gravida orci eget ullamcorper aliquam. Maecenas ut purus vel mauris efficitur porttitor eget eu ante. Nulla elit urna, sollicitudin vel quam vitae, rutrum mollis ipsum. Vivamus condimentum aliquam viverra. Maecenas suscipit pharetra tortor efficitur tempor. Sed ut ullamcorper quam, non vulputate sapien. Suspendisse malesuada felis a accumsan dapibus.Ut at feugiat eros, ac eleifend erat. Aenean rhoncus diam et est vehicula, vel finibus mi imperdiet. Nulla gravida urna erat, et vulputate enim bibendum et. Mauris commodo pulvinar blandit. Duis placerat tortor ut diam convallis, at fringilla diam tristique. Etiam viverra interdum urna, vitae porta mauris blandit vitae. Etiam massa mauris non.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus eu egestas nibh. Duis vestibulum, ligula at efficitur sagittis, nulla magna finibus ex, a faucibus ipsum quam vel nibh. Donec nec sollicitudin magna. Aliquam consectetur tellus ante, a placerat libero tempus at. Donec in tristique mauris, sed ornare odio. Nulla gravida orci eget ullamcorper aliquam. Maecenas ut purus vel mauris efficitur porttitor eget eu ante. Nulla elit urna, sollicitudin vel quam vitae, rutrum mollis ipsum. Vivamus condimentum aliquam viverra. Maecenas suscipit pharetra tortor efficitur tempor. Sed ut ullamcorper quam, non vulputate sapien. Suspendisse malesuada felis a accumsan dapibus.Ut at feugiat eros, ac eleifend erat. Aenean rhoncus diam et est vehicula, vel finibus mi imperdiet. Nulla gravida urna erat, et vulputate enim bibendum et. Mauris commodo pulvinar blandit. Duis placerat tortor ut diam convallis, at fringilla diam tristique. Etiam viverra interdum urna, vitae porta mauris blandit vitae. Etiam massa mauris non.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus eu egestas nibh. Duis vestibulum, ligula at efficitur sagittis, nulla magna finibus ex, a faucibus ipsum quam vel nibh. Donec nec sollicitudin magna. Aliquam consectetur tellus ante, a placerat libero tempus at. Donec in tristique mauris, sed ornare odio. Nulla gravida orci eget ullamcorper aliquam. Maecenas ut purus vel mauris efficitur porttitor eget eu ante. Nulla elit urna, sollicitudin vel quam vitae, rutrum mollis ipsum. Vivamus condimentum aliquam viverra. Maecenas suscipit pharetra tortor efficitur tempor. Sed ut ullamcorper quam, non vulputate sapien. Suspendisse malesuada felis a accumsan dapibus.Ut at feugiat eros, ac eleifend erat. Aenean rhoncus diam et est vehicula, vel finibus mi imperdiet. Nulla gravida urna erat, et vulputate enim bibendum et. Mauris commodo pulvinar blandit. Duis placerat tortor ut diam convallis, at fringilla diam tristique. Etiam viverra interdum urna, vitae porta mauris blandit vitae. Etiam massa mauris non.";

#endif
