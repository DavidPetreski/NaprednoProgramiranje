#include <iostream>
#include <algorithm>
#include <ctime>

int main() {
    // Низа на картите од шпилот
    const char* karti[] = {
        "Кец срце", "два срце", "Три срце", "Четири срце", "Пет срце" , "Шест срце", "Седум срце", "Осум срце", "Девет срце",  "Десет срце", "Џандар срце", "Кралица срце", "Крал срце",
        "Кец Локум", "Два локум", "Три локум", "Четири локум", "Пет локум", "Шест локум", "Седум локум", "Осум локум", "Девет локум", "Десет локум", "Џокер локум", "Кралица локум", "Крал локум",
        "Кец детелина", "два детелина", "Три детелина", "Четири детелина", "Пет детелина", "Шест детелина", "Седум детелина", "Осум детелина", "Девет детелина", "Десет детелина", "Џандар детелина", "Кралица детелина", "крал детелина",
        "Кец лист" , "Два лист", "Три лист", "Четири лист", "Пет лист", "Шест лист", "Седум лист", "Осум лист", "Девет лист", "Десет лист", "Џандар лист", "Кралица лист", "Крал лист"
    };

    //  Големината на низата
    const int numkarti = sizeof(karti) / sizeof(karti[0]);

    std::cout << "ПОДРЕДЕН ШПИЛ:" << std::endl;
    // Печатење на почетната низа на картите
    for (int i = 0; i < numkarti; ++i) {
        std::cout << karti[i] << std::endl;
    }

    // Генератор на случаен број со тековно време
    std::srand(std::time(nullptr));

   //Создава низа во стил на Ц за да ги држи Jокерите
    const char* jokers[] = {
        "ЦРН ЏОКЕР",
        "ЦРВЕН ЏОКЕР"
    };
    //големината на низата Jокери
    const int numJokers = sizeof(jokers) / sizeof(jokers[0]);

    const char* deck[numkarti + numJokers];
    //Копирајте ја низата карти
    std::copy(karti, karti + numkarti, deck);

    // Ги додава  Jокерите до крајот на низата
    std::copy(jokers, jokers + numJokers, deck + numkarti);

    const int numCardsWithJokers = numkarti + numJokers;

    // Мешање на картите
     std::cout << "\nИЗМЕШАН ШПИЛ:" << std::endl;
    for (int i = numCardsWithJokers - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        const char* temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Печатење на измешаниот шпил карти 
    for (int i = 0; i < numCardsWithJokers; ++i) {
        std::cout << deck[i] << "\n";
    }

    return 0;
}