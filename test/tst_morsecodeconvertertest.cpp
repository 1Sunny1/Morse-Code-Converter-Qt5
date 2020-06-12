#include <QtTest>
#include <QCoreApplication>
#include "../src/MorseCodeConverter.h"
// add necessary includes here

class MorseCodeConverterTest : public QObject
{
    Q_OBJECT

public:
    MorseCodeConverterTest() = default;

private slots:
    void IsCharacterEqualToCode();
    void PassingEmptyStringReturnsEmptyString();
    void PassingSpaceReturnsTwoSpaces();
    void PassingExcludedCharacterReturnsEmptyString();
    void PassingSentenceReturnsProperCode();

private:
    std::unique_ptr<MorseCodeConverter> const Converter = std::make_unique<MorseCodeConverter>();

};

void MorseCodeConverterTest::IsCharacterEqualToCode() {
    QString result = Converter->TextToCode("a");
    QString result2 = Converter->TextToCode("1");
    QString result3 = Converter->TextToCode("/");
    QCOMPARE(result, "._  ");
    QCOMPARE(result2, ".____  ");
    QCOMPARE(result3, "_.._.  ");
}

void MorseCodeConverterTest::PassingEmptyStringReturnsEmptyString() {
    QString result = Converter->TextToCode("");
    QCOMPARE(result.isEmpty(), true);
}

void MorseCodeConverterTest::PassingSpaceReturnsTwoSpaces() {
    QString result = Converter->TextToCode(" ");
    QCOMPARE(result, "  ");
}

void MorseCodeConverterTest::PassingExcludedCharacterReturnsEmptyString() {
    QString result = Converter->TextToCode("ę");
    QCOMPARE(result.isEmpty(), true);
}

void MorseCodeConverterTest::PassingSentenceReturnsProperCode() {
    QString result = Converter->TextToCode("A cat has nine lives.");
    QString result2 = Converter->TextToCode("Curiosity killed the cat.");
    QString result3 = Converter->TextToCode("Easy come, easy go.");
    QCOMPARE(result, "._    _._.  ._  _    ....  ._  ...    _.  ..  _.  .    ._..  ..  ..._  .  ...  ._._._  ");
    QCOMPARE(result2, "_._.  .._  ._.  ..  ___  ...  ..  _  _.__    _._  ..  ._..  ._..  .  _..    _  ....  .    _._.  ._  _  ._._._  ");
    QCOMPARE(result3, ".  ._  ...  _.__    _._.  ___  __  .  __..__    .  ._  ...  _.__    __.  ___  ._._._  ");
}

QTEST_MAIN(MorseCodeConverterTest)

#include "tst_morsecodeconvertertest.moc"
