#pragma once

#define LAYER_ID_GLOBAL -1

#ifdef ARTSEY_SIZE_40P
// 40% ARTSEY layer IDs
#define LAYER_ID_BASE 0
#define LAYER_ID_40P_BASE 1
#define LAYER_ID_40P_FUNCTION 2
#define LAYER_ID_40P_NAVIGATION 3
#define LAYER_ID_NUMBERS 4
#define LAYER_ID_SYMBOLS 5
#define LAYER_ID_PARENTHETICALS 6
#define LAYER_ID_NAVIGATION 7
#define LAYER_ID_CUSTOM 8
#define LAYER_ID_MOUSE 9
#define LAYER_ID_BIG_SYM 10
#define LAYER_ID_BIG_FUN 11
#else
// Standard and Big ARTSEY layer IDs
#define LAYER_ID_BASE 0
#define LAYER_ID_NUMBERS 1
#define LAYER_ID_SYMBOLS 2
#define LAYER_ID_PARENTHETICALS 3
#define LAYER_ID_NAVIGATION 4
#define LAYER_ID_CUSTOM 5
#define LAYER_ID_MOUSE 6
#define LAYER_ID_BIG_SYM 7
#define LAYER_ID_BIG_FUN 8
#endif

// /////////
// User remixes / tweaks
#if __has_include("remixes/remix_layer_ids.h")
#include "remixes/remix_layer_ids.h"
#endif
