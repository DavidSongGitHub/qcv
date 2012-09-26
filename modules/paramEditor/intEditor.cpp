/*
 * Copyright (C) 2012 Hernan Badino <hernan.badino@gmail.com>
 *
 * This file is part of QCV
 *
 * QCV is under the terms of the GNU Lesser General Public License
 * version 3. See the GNU LGPL version 3 for details.
 * QCV is distributed "AS IS" without ANY WARRANTY, without even the
 * implied warranty of merchantability or fitness for a particular
 * purpose. 
 *
 * In no event shall the authors or contributors be liable
 * for any direct, indirect, incidental, special, exemplary, or
 * consequential damages arising in any way out of the use of this
 * software.
 *
 * By downloading, copying, installing or using the software you agree
 * to this license. Do not download, install, copy or use the
 * software, if you do not agree to this license.
 */


/*@@@**************************************************************************
 * \file  intEditor
 * \author Hernan Badino
 * \notes 
 *******************************************************************************
 *****             (C) Hernan Badino 2012 - All Rights Reserved            *****
 ******************************************************************************/

/* INCLUDES */
#include "intEditor.h"

#include <QLineEdit>
#include <QHBoxLayout>
#include <math.h>

using namespace QCV;

CIntEditor::CIntEditor( int        f_value_i,
                        QWidget *     f_parent_p )
        : QWidget (               f_parent_p ),
          m_qle_p (                     NULL ),
          m_value_i (              f_value_i )
{
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);

    m_qle_p = new QLineEdit ( this );

    sizePolicy.setHeightForWidth(m_qle_p->sizePolicy().hasHeightForWidth());
    m_qle_p -> setSizePolicy ( sizePolicy );    

    m_qle_p -> setText ( QString::number(m_value_i) );    

    QGridLayout *layout_p = new QGridLayout( this );
    layout_p -> addWidget ( m_qle_p );
    
    connect( m_qle_p,   SIGNAL( editingFinished() ),
             this,      SLOT(   lineEditChanged() ) );
}

CIntEditor::~CIntEditor ()
{}

void
CIntEditor::lineEditChanged()
{
    QString str = m_qle_p->text();
    bool ok;
    int newVal_i = str.toInt(&ok);

    if ( ok && newVal_i != m_value_i )
    {
        m_value_i = newVal_i;
        emit valueChanged( m_value_i );
    }

    m_qle_p -> setText ( QString::number( m_value_i ) );
}

bool
CIntEditor::setValue( int f_value_i )
{
    m_value_i = f_value_i;
    m_qle_p -> setText ( QString::number( m_value_i ) );
    return true;
}

QSize CIntEditor::sizeHint () const
{
    return QSize(10,10);
}