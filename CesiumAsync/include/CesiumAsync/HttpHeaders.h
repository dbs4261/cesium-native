#pragma once

#include <string>
#include <map>

namespace CesiumAsync {
    struct CaseInsensitiveCompare
    {
        bool operator() (const std::string& s1, const std::string& s2) const;
    };

	using HttpHeaders = std::map<std::string, std::string, CaseInsensitiveCompare>;
}
