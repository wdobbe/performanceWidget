#include "graphpainter.h"
#include "painterutils.h"
#include <stdio.h>
#include <iostream>
GraphPainter::GraphPainter(QPaintDevice * widget):
PerformancePainter(widget)

{
    // Initializing colors
    m_color1 =(QColor(0,255,0,255));
    m_color2 = (QColor(0,180,0,120));

}



void GraphPainter::paint()
{
    //Create a new painter
    QPainter qpN(m_widget);
    //Draw gird and BG
    drawBackground(qpN);
    drawGrid(qpN);

    //Set a white color for the main rectangle
    qpN.setPen(QColor(255,255,255,255));

    //Compute size of the data and step size
    int size = m_cache.size();
    int sizeLess  = size -1;

    if (sizeLess <= 0)
    {
        sizeLess = 1;

    }
    float steps = (m_width- m_cache.size() ) / (size);
    for(int i = 0 ; i < (size);i++)
    {
        //Let set needed colors for the background and borer
        qpN.setPen(QColor(244,244,244,255));
        qpN.setBrush(QColor(100,100,100,0));
        QRectF boundingRect((steps*(i))+(i*2), 0, (steps), m_height-1);
        //qpN.drawRoundedRect((steps*(i))+(i*2) ,0,(steps),m_height-1,
        //                 3,3,Qt::AbsoluteSize);
        qpN.drawRoundedRect(boundingRect, 3, 3, Qt::AbsoluteSize);
        qpN.setFont(QFont("Helvetica", 30, QFont::Bold));
        qpN.setOpacity(0.3);
        qpN.drawText(boundingRect, Qt::AlignCenter, m_cache[i].backGroundText());
        qpN.setOpacity(1.0);

        //lets use our utils to draw the graph
        painterUtils::drawRectangleGraph(qpN,(steps*(i))+(i*2)-1,
                                         steps,m_height,m_cache[i].values(),
                                         m_color1,m_color2);
    }


}


