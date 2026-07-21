#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "funciones.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->pageBienvenida);

    connect(ui->btnIngresar, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageMenu);
    });

    connect(ui->btnCreditos, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageCreditos);
    });

    connect(ui->btnSalir, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageBienvenida);
    });
    connect(ui->btnSalir_2, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageBienvenida);
    });
    connect(ui->btnAtras_5, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageBienvenida);
    });
    connect(ui->btnSalir, &QPushButton::clicked, this, &MainWindow::close);

    connect(ui->btnRegistro, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageAgregar);
    });
    connect(ui->btnMostrar, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageMostrar);
    });
    connect(ui->btnEliminar_2, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageEliminar);
    });
    connect(ui->btnActualizar, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageActualizar);
    });
    connect(ui->btnAtras_2, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageMenu);
    });
    connect(ui->btnAtras, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageMenu);
    });
    connect(ui->btnAtras_3, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageMenu);
    });
    connect(ui->btnAtras_4, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageMenu);
    });

    connect(ui->btnGuardar, &QPushButton::clicked, [=]() {
        if(ui->txtCodigo->text().isEmpty() ||
            ui->txtNombre->text().isEmpty() ||
            ui->txtGenero->text().isEmpty() ||
            ui->txtDuracion->text().isEmpty()) {

            ui->lblMensaje->setText("¡Error: Todos los campos son obligatorios!");
            return;
        }
        Pelicula nuevaPeli;
        nuevaPeli.codigo = ui->txtCodigo->text().toStdString();
        nuevaPeli.nombrePelicula = ui->txtNombre->text().toStdString();
        nuevaPeli.genero = ui->txtGenero->text().toStdString();
        nuevaPeli.duracion = ui->txtDuracion->text().toStdString();

        if(nuevaPeli.codigo.empty() || nuevaPeli.nombrePelicula.empty()) {
            ui->lblMensaje->setText("¡Error: Código y Nombre son obligatorios!");
            return;
        }

        agregar(nuevaPeli, "peliculas.txt");

        ui->lblMensaje->setText("¡Película agregada con éxito!");
        ui->txtCodigo->clear();
        ui->txtNombre->clear();
        ui->txtGenero->clear();
        ui->txtDuracion->clear();
    });


    //CONEXIÓN MOSTRAR PELÍCULAS
    connect(ui->btnMostrar, &QPushButton::clicked, [=]() {

        ui->tablaPeliculas->clearContents();
        ui->tablaPeliculas->setRowCount(0);

        vector<Pelicula> lista = leer("peliculas.txt");

        ui->tablaPeliculas->setColumnCount(4);
        QStringList headers = {"Código", "Nombre", "Género", "Duración"};
        ui->tablaPeliculas->setHorizontalHeaderLabels(headers);

        int fila = 0;
        for(const Pelicula& p : lista) {
            ui->tablaPeliculas->insertRow(fila);

            ui->tablaPeliculas->setItem(fila, 0, new QTableWidgetItem(QString::fromStdString(p.codigo)));
            ui->tablaPeliculas->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString(p.nombrePelicula)));
            ui->tablaPeliculas->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(p.genero)));
            ui->tablaPeliculas->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(p.duracion)));

            fila++;
        }
    });

    ui->txtNombrePelicula->setEnabled(false);
    ui->txtGenero_2->setEnabled(false);
    ui->txtDuracion_2->setEnabled(false);
    ui->btnGuardarCambios->setEnabled(false);

    // --- ACCIÓN DEL BOTÓN BUSCAR ---
    connect(ui->btnBuscar, &QPushButton::clicked, [=]() {
        string codigoBuscado = ui->txtCodigoBuscar->text().toStdString();

        Pelicula peliEncontrada = buscar(codigoBuscado, "peliculas.txt");

        if(peliEncontrada.codigo.empty()) {
            ui->lblMensaje->setText("¡El código no fue encontrado!");

            ui->txtNombrePelicula->clear();
            ui->txtGenero_2->clear();
            ui->txtDuracion_2->clear();
            ui->txtNombrePelicula->setEnabled(false);
            ui->txtGenero_2->setEnabled(false);
            ui->txtDuracion_2->setEnabled(false);
            ui->btnGuardarCambios->setEnabled(false);
        } else {
            ui->txtNombrePelicula->setText(QString::fromStdString(peliEncontrada.nombrePelicula));
            ui->txtGenero_2->setText(QString::fromStdString(peliEncontrada.genero));
            ui->txtDuracion_2->setText(QString::fromStdString(peliEncontrada.duracion));

            ui->txtNombrePelicula->setEnabled(true);
            ui->txtGenero_2->setEnabled(true);
            ui->txtDuracion_2->setEnabled(true);
            ui->btnGuardarCambios->setEnabled(true);

            ui->lblMensaje->setText("¡Película encontrada con éxito!");
        }
    });

    // --- BOTÓN GUARDAR CAMBIOS ---
    connect(ui->btnGuardarCambios, &QPushButton::clicked, [=]() {
        if(ui->txtNombre->text().isEmpty() ||
            ui->txtGenero->text().isEmpty() ||
            ui->txtDuracion->text().isEmpty()) {

            ui->lblMensaje->setText("¡Error: No puedes dejar campos vacíos al actualizar!");
            return;
        }

        string codigoBuscado = ui->txtCodigoBuscar->text().toStdString();

        Pelicula peliModificada;
        peliModificada.codigo = codigoBuscado;
        peliModificada.nombrePelicula = ui->txtNombrePelicula->text().toStdString();
        peliModificada.genero = ui->txtGenero_2->text().toStdString();
        peliModificada.duracion = ui->txtDuracion_2->text().toStdString();

        actualizar(codigoBuscado, peliModificada, "peliculas.txt");

        ui->lblMensaje_2->setText("¡Película actualizada con éxito!");

        ui->txtCodigoBuscar->clear();
        ui->txtNombrePelicula->clear();
        ui->txtGenero_2->clear();
        ui->txtDuracion_2->clear();

        ui->txtNombrePelicula->setEnabled(false);
        ui->txtGenero_2->setEnabled(false);
        ui->txtDuracion_2->setEnabled(false);
        ui->btnGuardarCambios->setEnabled(false);
    });

    // --- LÓGICA DE ELIMINACIÓN ---
    ui->btnEliminar->setEnabled(false);

    connect(ui->btnBuscar_2, &QPushButton::clicked, [=]() {
        string codigoBuscado = ui->txtCodigoEliminado->text().toStdString();

        Pelicula peliEncontrada = buscar(codigoBuscado, "peliculas.txt");

        if(peliEncontrada.codigo.empty()) {
            ui->lblMensaje_3->setText("¡El código no fue encontrado!");

            ui->lblPeliculaEliminada->setText("");
            ui->lblGeneroEliminado->setText("");
            ui->lblDuracionEliminada->setText("");
            ui->btnEliminar->setEnabled(false);
        } else {
            ui->lblPeliculaEliminada->setText(QString::fromStdString(peliEncontrada.nombrePelicula));
            ui->lblGeneroEliminado->setText(QString::fromStdString(peliEncontrada.genero));
            ui->lblDuracionEliminada->setText(QString::fromStdString(peliEncontrada.duracion));

            ui->lblMensaje_3->setText("¡Película encontrada! Pulse eliminar para confirmar.");
            ui->btnEliminar->setEnabled(true);
        }
    });

    connect(ui->btnEliminar, &QPushButton::clicked, [=]() {
        string codigoBuscado = ui->txtCodigoEliminado->text().toStdString();

        eliminar(codigoBuscado, "peliculas.txt");

        ui->lblMensaje_3->setText("¡Película eliminada con éxito!");

        ui->txtCodigoEliminado->clear();
        ui->lblPeliculaEliminada->setText("");
        ui->lblGeneroEliminado->setText("");
        ui->lblDuracionEliminada->setText("");
        ui->btnEliminar->setEnabled(false);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
