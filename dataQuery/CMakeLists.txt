project(performanceWidget_dataQuery)



INCLUDE_DIRECTORIES(
                     ${CMAKE_SOURCE_DIR}
                     ${Qt5Core_INCLUDE_DIRS}
                     ${Qt5Widgets_INCLUDE_DIRS}
)

file( GLOB PERFWIDGET_DATAQUERY_INCLUDES SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h )


set( PERFWIDGET_DATAQUERY_SOURCES cpudataquery.cpp
                                  dataquery.cpp
                                  queryresource.cpp
                                  ramdataquery.cpp
                                  valuecache.cpp
)

add_library( perfdataquery STATIC ${PERFWIDGET_DATAQUERY_SOURCES} ${PERFWIDGET_DATAQUERY_INCLUDES} )
target_link_libraries(perfdataquery Qt5::Core Qt5::Widgets)

#below is a dummy target to let the header files show up in QtCreator. It can safely be removed if needed.
add_custom_target(performanceWidget_dataQueryHeaderDummy SOURCES ${PERFWIDGET_DATAQUERY_INCLUDES} )

