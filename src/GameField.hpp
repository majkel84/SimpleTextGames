#pragma once

#include <map>
#include <memory>

enum class BoardField : char
{
    X,
    O,
    UNKNOWN
};

/*inline const char* convMap (BoardField cts)
{
    const std::map<BoardField,const char*> BoardFieldToChar {
        { BoardField::X, 'X'},
        { BoardField::O, 'O'},
        { BoardField::UNKNOWN, '*'}
    };
    auto it  = BoardFieldToChar.find(cts);
    return it == BoardFieldToChar.end() ? "Out of range" : it->second;
}

inline Genere convBackMap (char cts)
{
    const std::map<char, Genere> StringToGenere {
        { "Action", Genere::action },
        { "Anime", Genere::anime},
        { "Bigraphical", Genere::biographical },
        { "Detective", Genere::detective },
        { "Documentary", Genere::documentary },
        { "Drama", Genere::drama },
        { "Family", Genere::family },
        { "Fantasy", Genere::fantasy },
        { "Historical", Genere::historical },
        { "Horror", Genere::horror },
        { "Musical", Genere::musical },
        { "Romantic", Genere::romantic },
        { "S-F", Genere::sf },
        { "Thriller", Genere::thriller },
        { "War", Genere::war },
        { "Western", Genere::western },
        { "Unknown", Genere::unknown}
    };
    auto it  = StringToGenere.find(cts);
    return it == StringToGenere.end() ? Genere::unknown : it->second;
}*/
