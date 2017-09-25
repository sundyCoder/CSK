# Sundy
## QT Concepts
### 1. Programming with Qt
[http://doc.qt.io/qt-4.8/qt-basic-concepts.html](http://doc.qt.io/qt-4.8/qt-basic-concepts.html)

### 1. Qt Main Window Framework
A main window provides a framework for building an application's user interface. Qt has QMainWindow and its related classes for main window management. QMainWindow has its own layout to which you can add QToolBars, QDockWidgets, a QMenuBar, and a QStatusBar. The layout has a center area that can be occupied by any kind of widget. You can see an image of the layout below.
![](http://i.imgur.com/vYcGX1s.png)


### 2. Model/View
website: [http://doc.qt.io/qt-4.8/model-view-programming.html](http://doc.qt.io/qt-4.8/model-view-programming.html)

![](http://i.imgur.com/rttvf3c.jpg)

### Model classes
![](http://i.imgur.com/ORKm5ac.jpg)

### View classes
QListVeiw, QTreeView, QTableView

![](http://i.imgur.com/LDVAFSD.jpg)

### 3. Graphics View Framework
An overview of the Graphics View framework for interactive 2D graphics.

[http://doc.qt.io/qt-4.8/graphicsview.html](http://doc.qt.io/qt-4.8/graphicsview.html)

### Scene
QGraphicsScene provides the Graphics View scene. The scene has the following responsibilities:

		Providing a fast interface for managing a large number of items
		Propagating events to each item
		Managing item state, such as selection and focus handling
		Providing untransformed rendering functionality; mainly for printing

### View
QGraphicsView provides the view widget, which visualizes the contents of a scene. You can attach several views to the same scene, to provide several viewports into the same data set. The view widget is a scroll area, and provides scroll bars for navigating through large scenes. To enable OpenGL support, you can set a QGLWidget as the viewport by callingQGraphicsView::setViewport().

	QGraphicsScene scene;
	myPopulateScene(&scene);
	
	QGraphicsView view(&scene);
	view.show();

The view receives input events from the keyboard and mouse, and translates these to scene events (converting the coordinates used to scene coordinates where appropriate), before sending the events to the visualized scene.

### Item
QGraphicsItem is the base class for graphical items in a scene. Graphics View provides several standard items for typical shapes, such as rectangles (QGraphicsRectItem), ellipses (QGraphicsEllipseItem) and text items (QGraphicsTextItem), but the most powerful QGraphicsItem features are available when you write a custom item. Among other things, QGraphicsItemsupports the following features:
		Mouse press, move, release and double click events, as well as mouse hover events, wheel events, and context menu events.
		Keyboard input focus, and key events
		Drag and drop
		Grouping, both through parent-child relationships, and with QGraphicsItemGroup
		Collision detection

### Example
 ![](http://i.imgur.com/gYDljS3.png)

Item coordinates

	Items live in their own local coordinate system.

Scene coordinates

	The scene represents the base coordinate system for all its items
	
View coordinates

	View coordinates are the coordinates of the widget

Coordinate Mapping

### Key Features
		Zooming and rotating
		Printing
		Drag and Drop
		Cursors and Tooltips
		Animation
		OpenGL Rendering(渲染)
		Item Groups
		Widget and Layout
		QGraphicsWidget
		QGraphicsLayout
		Embedded Widget Support
	Performance
		Floating Point Instructions


