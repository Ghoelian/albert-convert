project(convert VERSION 1.0)

albert_plugin(
        NAME "Convert"
        DESCRIPTION "Convert between values"
        LONG_DESCRIPTION "${CMAKE_CURRENT_SOURCE_DIR}/README.md"
        LICENSE BSD-2
        URL https://github.com/Ghoelian/albert-convert
        MAINTAINERS @Ghoelian
        QT_DEPENDENCIES Widgets
)
