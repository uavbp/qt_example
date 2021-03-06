#ifndef SAXHANDLER_H
#define SAXHANDLER_H

#include <QXmlDefaultHandler>

class QTreeWidget;
class QTreeWidgetItem;

class SaxHandler : public QXmlDefaultHandler
{
public:
    SaxHandler(QTreeWidget *tree);

    bool readFile(const QString &fileName);

protected:
    bool startElement(const QString &namespaceURI,
                      const QString &localName,
                      const QString &qName,
                      const QXmlAttributes &attributes);
    bool endElement(const QString &namespaceURI,
                    const QString &localName,
                    const QString &qName);
    bool characters(const QString &str);
    bool fatalError(const QXmlParseException &exception);

private:
    QTreeWidget *treeWidget;
    QTreeWidgetItem *currentItem;
    QString currentText;
};

#endif
