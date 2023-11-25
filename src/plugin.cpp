#include "albert/albert.h"
#include "albert/extension/queryhandler/standarditem.h"
#include "plugin.h"

using namespace albert;
using namespace std;

int bases[] = {
        16,
        2,
        8,
        3,
        4,
        5,
        6,
        7,
        9,
        11,
        12,
        13,
        14,
        15};

string baseNames[] = {"", "", "Binary", "Base-3", "Base-4", "Base-5", "Base-6", "Base-7", "Octal", "Base-9", "Decimal",
                      "Base-11", "Base-12", "Base-13", "Base-14", "Base-15", "Hexadecimal"};

string toBase(unsigned n, unsigned base) {
    const string chars = "0123456789ABCDEF";
    return n < base ? chars.substr(n, 1) : toBase(n / base, base) + chars[n % base];
}

static shared_ptr<Item> buildItem(int base, const unsigned long long &query) {
    QString id = "base-";
    id.append(to_string(base));

    QString text = QString::fromStdString(toBase(query, base));

    return StandardItem::make(
            id,
            text,
            QString::fromStdString(baseNames[base]),
            QStringList({":convert"}),
            {
                    {"copy", "Copy", [text]() { albert::setClipboardText(text); }}
            }
    );
}

void Plugin::handleTriggerQuery(TriggerQuery *query) const {
    string queryString = query->string().toStdString();

    char* p;
    unsigned long long convertedQuery = strtoull(queryString.c_str(), &p, 10);

    if (*p) {
        throw "Invalid input";
    }

    for (int i = 0; i < 14; i++) {
        query->add(buildItem(bases[i], convertedQuery));
    }
}
