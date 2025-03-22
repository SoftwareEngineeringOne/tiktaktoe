# Copilot Instructions

## Documentation

When generating documentation, use these instructions and the templates provided below.
Try to make the doc comments concise but clear.

- All files should contain a top level comment.
- All public functions should be documented in the header file.
- All private functions should be documented at the definition in the source files.
  - private functions are always marked as static and do not have a `[module]_` prefix
- All structs and enums should be documented.
- All global variables should be documented.
- All "complicated" macros should be documented.
- All typedefs should be documented.

Functions which are declared in a header and implemted in a source file,
should only be documented in the header file!

Please also check the function content for anything that should be noted in the doc comments.


### Documentation templates

To ensure a uniform documentation all doc comments, should be loosely based on the following
templates. Irrelevant fields can and should be ommited to avoid bloat.

Only add a notes or details section for more complex things, or where it is relevant.
Dont repeat information already mentioned!

#### Files

```c
/**
 * @file [File name]
 *
 * @brief [Brief description]

 * @details
 * This file contains [...].
 *
 * @ingroup [HAL/Logic/Presentation/Util] !REQIURED for .h files!
 *
 * @see 
 *  [Header/Source] !REQIURED! only the filename needs to be given
 *  [Any other relevant references] !Do not repeat references in .c files, which exist in .h files
 *
 * @note
 *  [Additional notes, if relevant...]
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
```

#### Functions

Do not comment functions in .c files, which are commented in their corresponding .h files.

```c
/**
 * @brief [Brief description]
 *
 * @details 
 * [Detailed description, only if relevant]
 * 
 * @param[in/out/inout] param1 Description of paramater
 * ...
 *
 * @return [Description of return value, or "void"]
 *
 * @note [Any additional notes or constraints, if relevant.]
 * 
 * @internal [On static functions declared in .c files]
 */
```

#### Structs

```c
/**
 * @brief [Brief description]
 *
 * @details 
 * [Detailed description, only if relevant]
 *
 * @note [Any additional notes or constraints, if relevant.]
 */
 typedef struct {
    int member1; ///< [Description of member1] 
    float member2; ///< [Description of member2]
    // ...
} ExampleStruct;
```

#### Enums

```c
/**
 * @brief [Brief description]
 *
 * @details 
 * [Detailed description, only if relevant]
 *
 * @note [Any additional notes or constraints, if relevant.]
 */
 typedef enum {
    ENUM_VALUE1; ///< [Description of ENUM_VALUE1]
    ENUM_VALUE2; ///< [Description of ENUM_VALUE2]
    ENUM_VALUE3; ///< [Description of ENUM_VALUE3]
    // ...
} ExampleEnum;

```

#### Typedefs

```c
/**
 * @brief [Brief description]
 *
 * @details 
 * [Detailed description, only if relevant]
 *
 * @note [Any additional notes or constraints, if relevant.]
 */
typedef unsigned long ExampleType;
```

#### Macros

```c
/**
 * @def EXAMPLE_MACRO
 * @brief [Short description of what the macro does or represents.]
 *
 * @details
 * [If neccessary, explain the purpose of the macro, 
 *  parameters (if function-like macro),...]
 *
 * @note [Any additional notes or constraints, if relevant.]
 *
 * Example: [if relevant]
 * @code
 *   int value = MY_MACRO;
 * @endcode
 */
#define EXAMPLE_MACRO 42
```

Or alternatively for a brief description:

```c
#define EXAMPLE_MACRO 42 ///< [Brief description]
```

#### Global Variables

```c
/**
 * @brief [Brief description]
 *
 * @details 
 * [What global variable is used for, scope, and initialization details.]
 *
 * @note [Any additional notes or constraints, if relevant.]
 */
extern int g_exampleGlobal;
```
