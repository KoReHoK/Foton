#pragma once

class PersonsModel;

// ********************************************************************************
class ModelViewDemoWidget : public QWidget {
    Q_OBJECT

public:
    ModelViewDemoWidget( QWidget* parent = 0 );

public slots:
    void onAppend(QString desc, int hotKey, byte keypad, int code, bool good, bool butt, bool foto);

private:
    QTableView* m_view;
    PersonsModel* m_model;

    QLineEdit* m_surnameEdit;
    QLineEdit* m_nameEdit;
    QLineEdit* m_patronymicEdit;
};

// ********************************************************************************
class PersonsModel : public QAbstractTableModel {
    Q_OBJECT
public:
    PersonsModel( QObject* parent = 0 );

    int rowCount( const QModelIndex& parent ) const;
    int columnCount( const QModelIndex& parent ) const;
    QVariant data( const QModelIndex& index, int role ) const;
    bool setData( const QModelIndex& index, const QVariant& value, int role );
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;
    Qt::ItemFlags flags( const QModelIndex& index ) const;

    void appendPerson(QString desc, int hotKey, byte keypad, int code, bool good, bool butt, bool foto);

public slots:
    void removeSelected();

private:
    enum Column {
        CODE = 0,
        DESCRIPTION,
        COLOR,
        KEYBOARD,
		JOYSTIK,
		GOOD,
		BUTTON,
		AUTOFOTO,
		SELECTION,
        LAST
    };

    typedef QHash< Column, QVariant > PersonData;
    typedef QList< PersonData > Persons;
    Persons m_persons;

};