#include "idgenerator.h"

#include <unordered_set>

using StringReverseIterator = std::reverse_iterator<std::string::iterator>;

// Константы, функции и пр. предназначенные для использования исключительно в 
// текущей единице трансляции
namespace{
    static const std::unordered_set<char> illegalCharacters{ ///< Множество запрещенных символов
        'D','F','G','J','M','Q','V','0'
    };

    /**
     * @brief Проверяет, не является ли символ запрещенным
     * @param[in] character - ссылка на символ
     * @return true если символ является запрещенным, иначе - false
     */ 
    bool isIllegalCharacter(const char& character)
    {
        return illegalCharacters.find(character) != illegalCharacters.end();
    }

    /**
     * @brief Безопасно двигает rev итератор
     * @param[in] it - ссылка на объект итератора
     * @param[in] end - ссылка на элемент, следующий за последним в контейнере
     * @param[in] n - количество позиций, на которое необходимо сдвинуть итератор
     */
    bool safelyMoveIterator(StringReverseIterator& it,
                            const StringReverseIterator& end,
                            int n)
    {
        while(n > 0){
            if(it == end)
                return false;
            n--;
            it++;
        }

        return true;
    }
}

IdGenerator::IdGenerator()
{}

IdGenerator::~IdGenerator()
{}

std::string IdGenerator::getNextId(std::string id) const
{
    findNextId(id);
    return id;
}

void IdGenerator::getNextIdInPlace(std::string& id) const
{
    findNextId(id);
}

void IdGenerator::findNextId(std::string& id) const
{
    auto r = id.rbegin();
    auto l = r;

    if(!::safelyMoveIterator(l, id.rend(), 1))
        return;
  
    while(l != id.rend()){
        char& r_char = *r;
        char& l_char = *l;
        r_char++;

        if(r_char > '9'){
            r_char = '1';
            l_char++;
        }

        while(::isIllegalCharacter(l_char))
            l_char++;

        if(l_char > 'Z'){
            l_char = 'A';

            if(!::safelyMoveIterator(l, id.rend(), 3)){
                id.insert(id.size(),"-A1");
                return;
            }
        }else
            return;

        ::safelyMoveIterator(r, id.rend(), 3);
    }
}
