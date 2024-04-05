#include "MainWindow.h"
#include "SettingEditor.h"
#include "QMTabs.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedLayout>
#include <QMScrollBar.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;

    widget->setLayout(layout);

    QStackedLayout *stack = new QStackedLayout;
    auto qtmtabs = new QtMaterialTabs(widget);
    qtmtabs->setDirection(QBoxLayout::Direction::TopToBottom);
    qtmtabs->setHaloVisible(false);
    qtmtabs->addTab("App Bar");
    qtmtabs->addTab("Auto Complete");
    qtmtabs->addTab("Avatar");
    qtmtabs->addTab("Badge");
    qtmtabs->addTab("Checkbox");
    qtmtabs->addTab("Circular Progress");
    qtmtabs->addTab("Dialog");
    qtmtabs->addTab("Drawer");
    qtmtabs->addTab("Floating Action Button");
    qtmtabs->addTab("Flat Button");
    qtmtabs->addTab("Icon Button");
    qtmtabs->addTab("Menu");
    qtmtabs->addTab("Progress");
    qtmtabs->addTab("Radio Button");
    qtmtabs->addTab("Raised Button");
    qtmtabs->addTab("ScrollBar");
    qtmtabs->addTab("Slider");
    qtmtabs->addTab("Snackbar");
    qtmtabs->addTab("Tabs");
    qtmtabs->addTab("Text Field");
    qtmtabs->addTab("Toggle");
    qtmtabs->addTab("Divider");

    qtmtabs->setInkBarPosition(QtMaterialTabsInkBar::InkBarPosition::LEFT);

    //    qtmtabs->setMaximumHeight(200);
    auto scroll = new QtMaterialScrollBar;

    //    qtmtabs->setVerticalScrollBar(scroll);
    scroll->setOrientation(Qt::Vertical);
    QListWidget *list = new QListWidget;
    layout->addWidget(qtmtabs);
    //    layout->addWidget(list);

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

    QObject::connect(qtmtabs, &QtMaterialTabs::currentChanged,
                     [=](int idx) { stack->setCurrentIndex(idx); });
}

MainWindow::~MainWindow()
{
}
