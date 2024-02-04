#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <string>

class IdGenerator
{
public:
    IdGenerator();
    virtual ~IdGenerator();

    /**
     * @brief Возвращает идентификатор, следующий за id
     * @param id - вдентификатор в виде объекта строки
     * @return следующий идентификатор в виде строки
     */
    std::string getNextId(std::string id) const;

    /**
     * @brief Формирует идентификатор, следующий за id (in-place версия)
     * @param id - ссылка на объект строки вдентификатора
     */
    void getNextIdInPlace(std::string& id) const;

private:
    /**
     * @brief Выполняет поиск идентификатора, следующего за id (in-place)
     * @param id - ссылка на объект строки вдентификатора
     */
    void findNextId(std::string& id) const;
};

#endif //IDGENERATOR_H