#include "MainWindow.h"
#include "SettingEditor.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;

    widget->setLayout(layout);

    QStackedLayout *stack = new QStackedLayout;
    QListWidget *list = new QListWidget;

    layout->addWidget(list);
    layout->addLayout(stack);

    layout->setStretch(1, 2);

    setCentralWidget(widget);

    auto *avatar = new AvatarSettingsEditor;
    auto *badge = new BadgeSettingsEditor;
    auto *checkbox = new CheckBoxSettingsEditor;
    auto *fab = new FloatingActionButtonSettingsEditor;
    auto *raisedButton = new RaisedButtonSettingsEditor;
    auto *flatButton = new FlatButtonSettingsEditor;
    auto *iconButton = new IconButtonSettingsEditor;
    auto *progress = new ProgressSettingsEditor;
    auto *circularProgress = new CircularProgressSettingsEditor;
    auto *slider = new SliderSettingsEditor;
    auto *radioButton = new RadioButtonSettingsEditor;
    auto *toggle = new ToggleSettingsEditor;
    auto *textField = new TextFieldSettingsEditor;
    auto *tabs = new TabsSettingsEditor;
    auto *snackbar = new SnackbarSettingsEditor;
    auto *dialog = new DialogSettingsEditor;
    auto *drawer = new DrawerSettingsEditor;
    auto *scrollBar = new ScrollBarSettingsEditor;
    auto *appBar = new AppBarSettingsEditor;
    auto *autocomplete = new AutoCompleteSettingsEditor;
    auto *menu = new MenuSettingsEditor;
    auto *divider = new DividerSettingsEditor;

    stack->addWidget(appBar);
    stack->addWidget(autocomplete);
    stack->addWidget(avatar);
    stack->addWidget(badge);
    stack->addWidget(checkbox);
    stack->addWidget(circularProgress);
    stack->addWidget(dialog);
    stack->addWidget(drawer);
    stack->addWidget(fab);
    stack->addWidget(flatButton);
    stack->addWidget(iconButton);
    stack->addWidget(menu);
    stack->addWidget(progress);
    stack->addWidget(radioButton);
    stack->addWidget(raisedButton);
    stack->addWidget(scrollBar);
    stack->addWidget(slider);
    stack->addWidget(snackbar);
    stack->addWidget(tabs);
    stack->addWidget(textField);
    stack->addWidget(toggle);
    stack->addWidget(divider);

    list->addItem("App Bar");
    list->addItem("Auto Complete");
    list->addItem("Avatar");
    list->addItem("Badge");
    list->addItem("Checkbox");
    list->addItem("Circular Progress");
    list->addItem("Dialog");
    list->addItem("Drawer");
    list->addItem("Floating Action Button");
    list->addItem("Flat Button");
    list->addItem("Icon Button");
    list->addItem("Menu");
    list->addItem("Progress");
    list->addItem("Radio Button");
    list->addItem("Raised Button");
    list->addItem("ScrollBar");
    list->addItem("Slider");
    list->addItem("Snackbar");
    list->addItem("Tabs");
    list->addItem("Text Field");
    list->addItem("Toggle");
    list->addItem("Divider");
    list->setCurrentRow(0);

    QObject::connect(list,  &QListWidget::currentItemChanged,
        [=](QListWidgetItem *current, QListWidgetItem *previous)
    {
        Q_UNUSED(current)
        Q_UNUSED(previous)
        stack->setCurrentIndex(list->currentRow());
    });
}

MainWindow::~MainWindow()
{
}
