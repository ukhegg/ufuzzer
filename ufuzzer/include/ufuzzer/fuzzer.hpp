//
// Created by ukhegg on 26.01.19.
//

#ifndef UFUZZER_FUZZER_HPP
#define UFUZZER_FUZZER_HPP

#include <map>
#include <memory>
#include <string>

#include <gsl/gsl>

#include "ufuzzer/ufuzzer_api.hpp"
#include "ufuzzer/i_fuzzing_fixture.hpp"

namespace ufuzzer {
    class UFUZZER_API fuzzer {
    public:
        using fixture_ptr = std::shared_ptr<i_fuzzing_fixture>;

        void register_fixture(std::string_view const& name, gsl::not_null<fixture_ptr> fixture)
        {

        }
    private:
        std::map<std::string, fixture_ptr> fixtures_;
    };
}


#endif //UFUZZER_FUZZER_HPP
