#pragma once
#include <string>
#include "example.hpp"
#include <iostream>

namespace MyLibrary {

    /**
     * @brief some subclass
     */
    template<typename TemplatedClass>
    class SubclassExample : public Example {
    public:

        /**
         * @bug second bug
         * @return
         */
        int virtualfunc() override;

        /**
         * @brief Template function function
         */
        template <typename T>
        std::shared_ptr<std::string> function_template_test(std::shared_ptr<T>& param);

        /**
         * @brief Extra long function with lots of parameters and many template types.
         *
         * Also has a long return type.
         *
         * @param param1 first parameter
         * @param param2 second parameter
         * @param parameter3 third parameter
         */
        template <typename T, typename Foo, typename Bar, typename Alice, typename Bob, typename Charlie, typename Hello, typename World>
        /**
         * @brief Processes multiple inputs and conditionally outputs a console message.
         *
         * This function accepts a mix of shared pointers, a flag for conditional behavior,
         * and additional parameters of various types. It demonstrates handling of multiple
         * template arguments and parameters by outputting a message to the console. The function
         * is intended to return a pair of strings that represent processed results.
         *
         * @tparam T The type associated with the first shared pointer.
         * @tparam Foo Unused template parameter.
         * @tparam Bar Unused template parameter.
         * @tparam Alice The type of the fourth parameter.
         * @tparam Bob The type of the fifth parameter.
         * @tparam Charlie Unused template parameter.
         * @tparam Hello Unused template parameter.
         * @tparam World Unused template parameter.
         * @param param1 A shared pointer to an object of type T.
         * @param param2 A shared pointer to a string used as input.
         * @param parameter3 A boolean flag influencing the function's conditional logic.
         * @param paramater4 An additional input parameter of type Alice.
         * @param parameter5 An additional input parameter of type Bob.
         * @return A pair of strings representing the processed results.
         */
        std::pair<std::string, std::string> long_function_with_many_parameters(std::shared_ptr<T>& param1, std::shared_ptr<std::string>& param2, bool parameter3, Alice paramater4 Bob parameter 5) {
            if(true) {
                std::cout << "this even has some code." << std::endl;
            }
        }

    };

}

