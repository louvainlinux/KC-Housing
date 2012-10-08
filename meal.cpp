/*
 * Copyright (c) 2012, Olivier Tilmans
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 **/

#include "meal.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>

Meal::Meal(QWidget *parent) :
    QWidget(parent)
{
}

void Meal::buildGUI(const QString& connection)
{
}

void Meal::initDB(const QString& connection)
{
    QSqlQuery query(QSqlDatabase::database(connection));
    query.exec("CREATE TABLE meals (id INTEGER PRIMARY KEY, "
               "date TEXT)");
    query.exec("INSERT INTO expenses(name, hidden) VALUES('"+tr("Meals")+"', 1)");
    query.exec("CREATE TABLE meals_subscription (id INTEGER PRIMARY KEY, "
               "personid INTEGER REFERENCES person(id) "
               "ON UPDATE CASCADE ON DELETE SET NULL, "
               "cross INTEGER)");
    query.exec("CREATE TABLE meals_ticket (id INTEGER PRIMARY KEY, "
               "ticketid INTEGER REFERENCES tickets(id) "
               "ON UPDATE CASCADE ON DELETE DELETE)");
}

QWidget* Meal::panel()
{
    return this;
}

const QString& Meal::title()
{
    static QString s = tr("Meal management");
    return s;
}

const QString& Meal::iconPath()
{
    static QString s(":/meals");
    return s;
}

void Meal::selectPanel()
{

}
