project(performanceWidget_painters)



INCLUDE_DIRECTORIES(
                     ${CMAKE_SOURCE_DIR}
                     ${Qt5Core_INCLUDE_DIRS}
                     ${Qt5Widgets_INCLUDE_DIRS}
)

file( GLOB PERFWIDGET_PAINTERS_INCLUDES SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h )


set( PERFWIDGET_PAINTERS_SOURCES  barspainter.cpp
                                  graphmulticolorpainter.cpp
                                  graphpainter.cpp
                                  painterutils.cpp
                                  performancepainter.cpp
)

add_library( perfpainters STATIC ${PERFWIDGET_PAINTERS_SOURCES} ${PERFWIDGET_PAINTERS_INCLUDES} )
target_link_libraries(perfpainters Qt5::Core Qt5::Widgets)

#below is a dummy target to let the header files show up in QtCreator. It can safely be removed if needed.
add_custom_target(performanceWidget_paintersHeaderDummy SOURCES ${PERFWIDGET_PAINTERS_INCLUDES} )

