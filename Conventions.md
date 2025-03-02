# Coding Conventions
- Conventional Commits (https://gist.github.com/qoomon/5dfcdf8eec66a051ecd85625518cfd13)
- The architecture is documented in this README
- Every file must have a short description at the beginning
- Every function must have a doc comment with a short description
- Not self describing code must be commented (should be avoided)
- Public functions start with the package name followed by an underscore
- Private functions should therefore not be called from outside
- Private functions should be defined in the beginning of the source files
- Private functions should be implemented in the source file, following the public functions

## File structure
All files should follow a common structure as defined below. Exceptions may be made, however
these should be explicitely explained.

### Header file structure
1. Module comment
2. Defines
3. global constants
4. global variables
5. structs
6. public function prototypes

### Source file structure
1. Module comment (may reference header comment and add information if needed)
2. module constants
3. module variables
4. private function prototypes
5. public function implementations
6. private function implementations


### Naming
#### Functions
- public functions should be prefixed with "`module_[...]`"
- private functions should be marked as `static` and prefixed with "`_[...]`"
- the function name itself should be written in `camelCase`
- a specialization may follow as a suffix, such as "`[...]_waiting`"


## Documentation
- All files should contain a top level comment structured similiar to this:
```c
/**
 * @file 
 *
 * @author 
 *
 * @date 
 *
 * @brief 
 *
 * @see 
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */
```
- All public functions should be documented in the header file
- All private functions should be documented at the definition in the source files

