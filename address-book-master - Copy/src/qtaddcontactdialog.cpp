#include "contact.h"
#include "qtaddcontactdialog.h"
#include <QDialog>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

QtAddContactDialog::QtAddContactDialog(Contact &c, QWidget *parent, Qt::WindowFlags f) :
            QDialog(parent, f), contactForm(new QtContactForm()), outContact(c)
{
    QVBoxLayout *mainContainer = new QVBoxLayout();
    mainContainer->addLayout(contactForm);

    QHBoxLayout *buttonContainer = new QHBoxLayout();
    QPushButton *addButton = new QPushButton("Add");
    QPushButton *cancelButton = new QPushButton("Cancel");
    QPushButton *saveButton = new QPushButton("Save");
    
    buttonContainer->addWidget(addButton);
    buttonContainer->addWidget(cancelButton);
    buttonContainer->addWidget(saveButton);
    mainContainer->addLayout(buttonContainer);

    connect(addButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(accept()));

    setLayout(mainContainer);
    setWindowTitle("New Contact");
}

void QtAddContactDialog::accept()
{
    outContact.firstName = contactForm->firstNameField->text().toStdString();
    outContact.lastName = contactForm->lastNameField->text().toStdString();
    outContact.address = contactForm->addressField->text().toStdString();
    outContact.phoneNumber = contactForm->phoneNumberField->text().toStdString();
    outContact.email = contactForm->emailField->text().toStdString();
    outContact.city = contactForm->cityField->text().toStdString();

    QDialog::accept();
}
