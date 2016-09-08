#Sundy
###Signal & Slot
Signals and slots are used for communication between objects. The signals and slots mechanism is a central feature of Qt and probably the part that differs most from the features provided by other frameworks.

###Introduction

In GUI programming, when we change one widget, we often want another widget to be notified. More generally, we want objects of any kind to be able to communicate with one another. For example, if a user clicks a Close button, we probably want the window's close() function to be called.

Older toolkits achieve this kind of communication using callbacks. A callback is a pointer to a function, so if you want a processing function to notify you about some event you pass a pointer to another function (the callback) to the processing function. The processing function then calls the callback when appropriate. Callbacks have two fundamental flaws: Firstly, they are not type-safe. We can never be certain that the processing function will call the callback with the correct arguments. Secondly, the callback is strongly coupled to the processing function since the processing function must know which callback to call.

###Signals and Slots
In Qt, we have an alternative to the callback technique: We use signals and slots. A signal is emitted when a particular event occurs. Qt's widgets have many predefined signals, but we can always subclass widgets to add our own signals to them. A slot is a function that is called in response to a particular signal. Qt's widgets have many pre-defined slots, but it is common practice to subclass widgets and add your own slots so that you can handle the signals that you are interested in.

![](http://i.imgur.com/wlXZHlN.jpg)

The signals and slots mechanism is type safe: The signature of a signal must match the signature of the receiving slot. (In fact a slot may have a shorter signature than the signal it receives because it can ignore extra arguments.) Since the signatures are compatible, the compiler can help us detect type mismatches. Signals and slots are loosely coupled: A class which emits a signal neither knows nor cares which slots receive the signal. Qt's signals and slots mechanism ensures that if you connect a signal to a slot, the slot will be called with the signal's parameters at the right time. Signals and slots can take any number of arguments of any type. They are completely type safe.

All classes that inherit from QObject or one of its subclasses (e.g., QWidget) can contain signals and slots. Signals are emitted by objects when they change their state in a way that may be interesting to other objects. This is all the object does to communicate. It does not know or care whether anything is receiving the signals it emits. This is true information encapsulation, and ensures that the object can be used as a software component.

Slots can be used for receiving signals, but they are also normal member functions. Just as an object does not know if anything receives its signals, a slot does not know if it has any signals connected to it. This ensures that truly independent components can be created with Qt.

You can connect as many signals as you want to a single slot, and a signal can be connected to as many slots as you need. It is even possible to connect a signal directly to another signal. (This will emit the second signal immediately whenever the first is emitted.)

Together, signals and slots make up a powerful component programming mechanism.

###A Small Example

A minimal C++ class declaration might read:

	class Counter
	{
	public:
	    Counter() { m_value = 0; }
	
	    int value() const { return m_value; }
	    void setValue(int value);
	
	private:
	    int m_value;
	};

A small QObject-based class might read:

	#include <QObject>
	
	class Counter : public QObject
	{
	    Q_OBJECT
	
	public:
	    Counter() { m_value = 0; }
	
	    int value() const { return m_value; }
	
	public slots:
	    void setValue(int value);
	
	signals:
	    void valueChanged(int newValue);
	
	private:
	    int m_value;
	};

The QObject-based version has the same internal state, and provides public methods to access the state, but in addition it has support for component programming using signals and slots. This class can tell the outside world that its state has changed by emitting a signal, valueChanged(), and it has a slot which other objects can send signals to.

All classes that contain signals or slots must mention Q_OBJECT at the top of their declaration. They must also derive (directly or indirectly) from QObject.

Slots are implemented by the application programmer. Here is a possible implementation of the Counter::setValue() slot:

	void Counter::setValue(int value)
	{
	    if (value != m_value) {
	        m_value = value;
	        emit valueChanged(value);
	    }
	}

The emit line emits the signal valueChanged() from the object, with the new value as argument.

In the following code snippet, we create two Counter objects and connect the first object's valueChanged() signal to the second object's setValue() slot using QObject::connect():

    Counter a, b;
    QObject::connect(&a, SIGNAL(valueChanged(int)),
                     &b, SLOT(setValue(int)));

    a.setValue(12);     // a.value() == 12, b.value() == 12
    b.setValue(48);     // a.value() == 12, b.value() == 48

Calling a.setValue(12) makes a emit a valueChanged(12) signal, which b will receive in its setValue() slot, i.e. b.setValue(12) is called. Then b emits the same valueChanged() signal, but since no slot has been connected to b's valueChanged() signal, the signal is ignored.

Note that the setValue() function sets the value and emits the signal only if value != m_value. This prevents infinite looping in the case of cyclic connections (e.g., if b.valueChanged() were connected to a.setValue()).

By default, for every connection you make, a signal is emitted; two signals are emitted for duplicate connections. You can break all of these connections with a single disconnect() call. If you pass the Qt::UniqueConnection type, the connection will only be made if it is not a duplicate. If there is already a duplicate (exact same signal to the exact same slot on the same objects), the connection will fail and connect will return false

This example illustrates that objects can work together without needing to know any information about each other. To enable this, the objects only need to be connected together, and this can be achieved with some simple QObject::connect() function calls, or with uic's automatic connections feature.

###Building the Example

The C++ preprocessor changes or removes the signals, slots, and emit keywords so that the compiler is presented with standard C++.

By running the moc on class definitions that contain signals or slots, a C++ source file is produced which should be compiled and linked with the other object files for the application. If you use qmake, the makefile rules to automatically invoke moc will be added to your project's makefile.

###Signals

Signals are emitted by an object when its internal state has changed in some way that might be interesting to the object's client or owner. Only the class that defines a signal and its subclasses can emit the signal.

When a signal is emitted, the slots connected to it are usually executed immediately, just like a normal function call. When this happens, the signals and slots mechanism is totally independent of any GUI event loop. Execution of the code following the emit statement will occur once all slots have returned. The situation is slightly different when using queued connections; in such a case, the code following the emit keyword will continue immediately, and the slots will be executed later.

If several slots are connected to one signal, the slots will be executed one after the other, in the order they have been connected, when the signal is emitted.

Signals are automatically generated by the moc and must not be implemented in the .cpp file. They can never have return types (i.e. use void).

A note about arguments: Our experience shows that signals and slots are more reusable if they do not use special types. If QScrollBar::valueChanged() were to use a special type such as the hypothetical QScrollBar::Range, it could only be connected to slots designed specifically for QScrollBar. Connecting different input widgets together would be impossible.

###Slots

A slot is called when a signal connected to it is emitted. Slots are normal C++ functions and can be called normally; their only special feature is that signals can be connected to them.

Since slots are normal member functions, they follow the normal C++ rules when called directly. However, as slots, they can be invoked by any component, regardless of its access level, via a signal-slot connection. This means that a signal emitted from an instance of an arbitrary class can cause a private slot to be invoked in an instance of an unrelated class.

You can also define slots to be virtual, which we have found quite useful in practice.

Compared to callbacks, signals and slots are slightly slower because of the increased flexibility they provide, although the difference for real applications is insignificant. In general, emitting a signal that is connected to some slots, is approximately ten times slower than calling the receivers directly, with non-virtual function calls. This is the overhead required to locate the connection object, to safely iterate over all connections (i.e. checking that subsequent receivers have not been destroyed during the emission), and to marshall any parameters in a generic fashion. While ten non-virtual function calls may sound like a lot, it's much less overhead than any new or delete operation, for example. As soon as you perform a string, vector or list operation that behind the scene requires new or delete, the signals and slots overhead is only responsible for a very small proportion of the complete function call costs.

The same is true whenever you do a system call in a slot; or indirectly call more than ten functions. On an i586-500, you can emit around 2,000,000 signals per second connected to one receiver, or around 1,200,000 per second connected to two receivers. The simplicity and flexibility of the signals and slots mechanism is well worth the overhead, which your users won't even notice.

Note that other libraries that define variables called signals or slots may cause compiler warnings and errors when compiled alongside a Qt-based application. To solve this problem, #undef the offending preprocessor symbol.


###Meta-Object Information

The meta-object compiler (moc) parses the class declaration in a C++ file and generates C++ code that initializes the meta-object. The meta-object contains the names of all the signal and slot members, as well as pointers to these functions.

The meta-object contains additional information such as the object's class name. You can also check if an object inherits a specific class, for example:

    if (widget->inherits("QAbstractButton")) {
        QAbstractButton *button = static_cast<QAbstractButton *>(widget);
        button->toggle();
    }

The meta-object information is also used by qobject_cast<T>(), which is similar to QObject::inherits() but is less error-prone:

    if (QAbstractButton *button = qobject_cast<QAbstractButton *>(widget))
        button->toggle();
See Meta-Object System for more information.


###A Real Example

Here is a simple commented example of a widget.

	#ifndef LCDNUMBER_H
	#define LCDNUMBER_H
	
	#include <QFrame>
	
	class LcdNumber : public QFrame
	{
	    Q_OBJECT
LcdNumber inherits QObject, which has most of the signal-slot knowledge, via QFrame and QWidget. It is somewhat similar to the built-in QLCDNumber widget.

The Q_OBJECT macro is expanded by the preprocessor to declare several member functions that are implemented by the moc; if you get compiler errors along the lines of "undefined reference to vtable for LcdNumber", you have probably forgotten to run the moc or to include the moc output in the link command.


	public:
	    LcdNumber(QWidget *parent = 0);
It's not obviously relevant to the moc, but if you inherit QWidget you almost certainly want to have the parent argument in your constructor and pass it to the base class's constructor.

Some destructors and member functions are omitted here; the moc ignores member functions.

	signals:
	    void overflow();

LcdNumber emits a signal when it is asked to show an impossible value.

If you don't care about overflow, or you know that overflow cannot occur, you can ignore the overflow() signal, i.e. don't connect it to any slot.

If on the other hand you want to call two different error functions when the number overflows, simply connect the signal to two different slots. Qt will call both (in the order they were connected).

	public slots:
	    void display(int num);
	    void display(double num);
	    void display(const QString &str);
	    void setHexMode();
	    void setDecMode();
	    void setOctMode();
	    void setBinMode();
	    void setSmallDecimalPoint(bool point);
	};
	
	#endif
A slot is a receiving function used to get information about state changes in other widgets. LcdNumber uses it, as the code above indicates, to set the displayed number. Since display() is part of the class's interface with the rest of the program, the slot is public.

Several of the example programs connect the valueChanged() signal of a QScrollBar to the display() slot, so the LCD number continuously shows the value of the scroll bar.

Note that display() is overloaded; Qt will select the appropriate version when you connect a signal to the slot. With callbacks, you'd have to find five different names and keep track of the types yourself.

Some irrelevant member functions have been omitted from this example.

###Signals And Slots With Default Arguments

The signatures of signals and slots may contain arguments, and the arguments can have default values. Consider QObject::destroyed():

void destroyed(QObject* = 0);
When a QObject is deleted, it emits this QObject::destroyed() signal. We want to catch this signal, wherever we might have a dangling reference to the deleted QObject, so we can clean it up. A suitable slot signature might be:

	void objectDestroyed(QObject* obj = 0);
To connect the signal to the slot, we use QObject::connect() and the SIGNAL() and SLOT() macros. The rule about whether to include arguments or not in the SIGNAL() and SLOT() macros, if the arguments have default values, is that the signature passed to the SIGNAL() macro must not have fewer arguments than the signature passed to the SLOT() macro.

All of these would work:

	connect(sender, SIGNAL(destroyed(QObject*)), this, SLOT(objectDestroyed(Qbject*)));
	connect(sender, SIGNAL(destroyed(QObject*)), this, SLOT(objectDestroyed()));
	connect(sender, SIGNAL(destroyed()), this, SLOT(objectDestroyed()));
But this one won't work:
	
	connect(sender, SIGNAL(destroyed()), this, SLOT(objectDestroyed(QObject*)));
...because the slot will be expecting a QObject that the signal will not send. This connection will report a runtime error.

###Advanced Signals and Slots Usage

For cases where you may require information on the sender of the signal, Qt provides the QObject::sender() function, which returns a pointer to the object that sent the signal.

The QSignalMapper class is provided for situations where many signals are connected to the same slot and the slot needs to handle each signal differently.

Suppose you have three push buttons that determine which file you will open: "Tax File", "Accounts File", or "Report File".

In order to open the correct file, you use QSignalMapper::setMapping() to map all the clicked() signals to a QSignalMapper object. Then you connect the file's QPushButton::clicked() signal to the QSignalMapper::map() slot.

 	signalMapper = new QSignalMapper(this);
    signalMapper->setMapping(taxFileButton, QString("taxfile.txt"));
    signalMapper->setMapping(accountFileButton, QString("accountsfile.txt"));
    signalMapper->setMapping(reportFileButton, QString("reportfile.txt"));

    connect(taxFileButton, SIGNAL(clicked()),
        signalMapper, SLOT (map()));
    connect(accountFileButton, SIGNAL(clicked()),
        signalMapper, SLOT (map()));
    connect(reportFileButton, SIGNAL(clicked()),
        signalMapper, SLOT (map()));


Then, you connect the mapped() signal to readFile() where a different file will be opened, depending on which push button is pressed.

    connect(signalMapper, SIGNAL(mapped(QString)),
        this, SLOT(readFile(QString)));
Note: The following code will compile and run, but due to signature normalization, the code will be slower.

//slower due to signature normalization at runtime

    connect(signalMapper, SIGNAL(mapped(const QString &)),
        this, SLOT(readFile(const QString &)));

###Using Qt with 3rd Party Signals and Slots

It is possible to use Qt with a 3rd party signal/slot mechanism. You can even use both mechanisms in the same project. Just add the following line to your qmake project (.pro) file.

	CONFIG += no_keywords
It tells Qt not to define the moc keywords signals, slots, and emit, because these names will be used by a 3rd party library, e.g. Boost. Then to continue using Qt signals and slots with the no_keywords flag, simply replace all uses of the Qt moc keywords in your sources with the corresponding Qt macros Q_SIGNALS (or Q_SIGNAL), Q_SLOTS (or Q_SLOT), and Q_EMIT.

See also Meta-Object System and Qt's Property System.


###Original
[http://doc.qt.io/qt-4.8/signalsandslots.html](http://doc.qt.io/qt-4.8/signalsandslots.html)