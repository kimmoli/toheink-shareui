/*
Copyright (c) 2014 kimmoli kimmo.lindholm@gmail.com @likimmo

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "converter.h"
#include <QSettings>
#include <QCoreApplication>
#include <QDebug>
#include <QImage>
#include <QTransform>


Converter::Converter(QObject *parent) :
    QObject(parent)
{
}

Converter::~Converter()
{
}

void Converter::convert(QString inputFileName, QString outputFileName)
{
    QImage inImg(inputFileName);

    QImage outImg = inImg;

    if (inImg.height() > inImg.width())
    {
        QTransform rot;
        rot.rotate(-90);

        outImg = outImg.transformed(rot);
    }

    outImg = outImg.convertToFormat(QImage::Format_Mono, Qt::MonoOnly);
    outImg = outImg.scaled(264, 176, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    outImg.save(outputFileName, "XBM");
}

