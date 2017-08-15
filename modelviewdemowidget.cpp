#include "stdafx.h"
#include "modelviewdemowidget.h"

// ********************************************************************************
ModelViewDemoWidget::ModelViewDemoWidget( QWidget* parent ) : QWidget( parent ) {
    QVBoxLayout* mainLayout = new QVBoxLayout;
    setLayout( mainLayout );

    m_view = new QTableView;
    //m_view->horizontalHeader()->setResizeMode( QHeaderView::Stretch );
    m_view->setModel( m_model = new PersonsModel );
    mainLayout->addWidget( m_view );

    QGridLayout* panelLayout = new QGridLayout;
    mainLayout->addLayout( panelLayout );

    QLabel* lbRemove = new QLabel( trUtf8( "<a href=\"#\">Удалить</a>" ) );
    connect( lbRemove, SIGNAL( linkActivated( QString ) ), m_model, SLOT( removeSelected() ) );
    lbRemove->setAlignment( Qt::AlignRight );
    panelLayout->addWidget( lbRemove, 0, 6 );
}

void ModelViewDemoWidget::onAppend(QString desc, int hotKey, byte keypad, int code, bool good, bool butt, bool foto) {
    m_model->appendPerson(desc, hotKey, keypad, code, good, butt, foto);
}

// ********************************************************************************
PersonsModel::PersonsModel( QObject* parent ) : QAbstractTableModel( parent ) {
}

int PersonsModel::rowCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return m_persons.count();
}

int PersonsModel::columnCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent )
    return LAST;
}

QVariant PersonsModel::data( const QModelIndex& index, int role ) const {
    if(
        !index.isValid() ||
        m_persons.count() <= index.row() ||
        ( role != Qt::DisplayRole && role != Qt::EditRole )
    ) {
        return QVariant();
    }

    return m_persons[ index.row() ][ Column( index.column() ) ];
}

bool PersonsModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( !index.isValid() || role != Qt::EditRole || m_persons.count() <= index.row() ) {
        return false;
    }

    m_persons[ index.row() ][ Column( index.column() ) ] = value;
    emit dataChanged( index, index );

    return true;
}

QVariant PersonsModel::headerData( int section, Qt::Orientation orientation, int role ) const {
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }

    if( orientation == Qt::Vertical ) {
        return section;
    }

    switch( section ) {
		case CODE:
			return trUtf8( "Код" );
		case DESCRIPTION:
			return trUtf8( "Описание" );
		case COLOR:
			return trUtf8( "Цвет" );
		case KEYBOARD:
			return trUtf8( "Клавиатура" );
		case JOYSTIK:
			return trUtf8("Джойстик");
		case GOOD:
			return trUtf8("Обход");
		case BUTTON:
			return trUtf8("Кнопка");
		case AUTOFOTO:
			return trUtf8("Автофото");
		case SELECTION:
			return trUtf8("Удалить");
    }

    return QVariant();
}

Qt::ItemFlags PersonsModel::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );
    if( index.isValid() ) {
        if( index.column() == SELECTION ) {
            flags |= Qt::ItemIsEditable;
        }
    }

    return flags;
}

void PersonsModel::appendPerson(QString desc, int hotKey, byte keypad, int code, bool good, bool butt, bool foto) {
    PersonData person;
	person[CODE] = code;
	person[DESCRIPTION] = desc;
	//person[COLOR]
	person[KEYBOARD] = hotKey;
	person[JOYSTIK] = keypad;
	person[GOOD] = good;
	person[BUTTON] = butt;
	person[AUTOFOTO] = foto;
	person[SELECTION] = false;

    int row = m_persons.count();
    beginInsertRows( QModelIndex(), row, row );
    m_persons.append( person );
    endInsertRows();
}

void PersonsModel::removeSelected() {
    int i = 0;
    Persons::iterator it = m_persons.begin();
    while( it != m_persons.end() ) {
        if( it->value( SELECTION, false ).toBool() ) {
            beginRemoveRows( QModelIndex(), i, i );
            it = m_persons.erase( it );
            endRemoveRows();
        } else {
            ++i;
            ++it;
        }

        if( it == m_persons.end() ) {
            break;
        }
    }
}
