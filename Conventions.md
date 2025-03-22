# 🤝 Coding Conventions

<div style="visibility:hidden">[TOC]</div>

- [Conventional Commits](https://gist.github.com/qoomon/5dfcdf8eec66a051ecd85625518cfd13)

## 📄 File structure

All files should follow a common structure as defined below. Exceptions may be made, however
these should be explicitely explained.

### Header file structure

1. Module comment
2. Defines
3. Global constants
4. Global variables
5. Structs
6. Public function prototypes

### Source file structure

1. Module comment (may reference header comment and add information if needed)
2. Module constants
3. Module variables
4. Private function prototypes
5. Public function implementations
6. Private function implementations

## 💬 Naming

### Files

- Files should use `snake_case` naming

### Functions

- Public functions should be prefixed with "`module_[...]`"
- Private functions should be marked as `static` and prefixed with "`_[...]`"
- The function name itself should be written in `camelCase`
- A specialization may follow as a suffix, such as "`[...]_waiting`"

### Variables

- All variables should use `snake_case` naming
- Global variables should be prefixed with `g_[...]`

### Macros

- Function macros should use the same naming as functions
- Other macros should use `SCREAMING_CASE` naming

## 📝 Documentation

- All files should contain a top level comment.
- All public functions should be documented in the header file.
- All private functions should be documented at the definition in the source files.
- All structs and enums should be documented.
- All global variables should be documented.
- All "complicated" macros should be documented.
- All typedefs should be documented.

### Documentation templates

To ensure a uniform documentation all doc comments, should be loosely based on the following
templates. Irrelevant fields can and should be ommited to avoid bloat.

<div class="tabbed">

- <b class="tab-title"> Files </b>

    ```c
    /**
     * @file  [File name]
     *
     * @brief [Brief description]
     *
     * @details
     * This file contains [...].
     *
     * @ingroup [HAL/Logic/Presentation/Utility]
     *
     * @see 
     *  [Header/Source]
     *  [Any other relevant]
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

- <b class="tab-title"> Functions </b>

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
     */
    void example_function(uint8_t param1);
    ```

- <b class="tab-title"> Structs </b>

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
        int member1; /**< [Description of member1] */
        float member2; /**< [Description of member2] */
        // ...
    } ExampleStruct;
    ```

- <b class="tab-title"> Enums </b>

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
        ENUM_VALUE1; /**< [Description of ENUM_VALUE1] */
        ENUM_VALUE2; /**< [Description of ENUM_VALUE2] */
        ENUM_VALUE3; /**< [Description of ENUM_VALUE3] */
        // ...
    } ExampleEnum;
    ```

- <b class="tab-title"> Typedefs </b>

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

- <b class="tab-title"> Macros </b>

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

- <b class="tab-title"> Global Variables </b>

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
</div>