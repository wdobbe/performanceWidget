project(performanceWidget_widgets)



INCLUDE_DIRECTORIES( 
                     ${CMAKE_SOURCE_DIR}
                     ${Qt5Core_INCLUDE_DIRS}
                     ${Qt5Widgets_INCLUDE_DIRS}
)

file( GLOB PERFWIDGET_WIDGETS_INCLUDES SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h )


set( PERFWIDGET_WIDGETS_SOURCES   cpuwidget.cpp
                                  performancewidget.cpp
                                  ramwidget.cpp
)

add_library( perfwidgets STATIC ${PERFWIDGET_WIDGETS_SOURCES} ${PERFWIDGET_WIDGETS_INCLUDES} )
target_link_libraries(perfwidgets Qt5::Core Qt5::Widgets)

#below is a dummy target to let the header files show up in QtCreator. It can safely be removed if needed.
add_custom_target(performanceWidget_widgetsHeaderDummy SOURCES ${PERFWIDGET_WIDGETS_INCLUDES} )

