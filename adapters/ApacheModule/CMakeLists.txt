
set (APACHEMODULE_SRC_FILES "src/ApacheModule.cpp")

set (APACHEMODULE_LIBRARIES "dl -lapreq2")

include_directories (include /usr/include/apreq2 /usr/include/apache2 /usr/include/httpd /usr/include/apr-1.0 /usr/include/apr-1 /opt/wps/include)

add_library (mod_answer SHARED ${APACHEMODULE_SRC_FILES})
set_target_properties(mod_answer PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION ${PROJECT_VERSION} PREFIX "")
target_link_libraries (mod_answer
	${PROJECT_NAME}
	${PROJECT_NAME}-module
	${MANDATORY_PACKAGES_LIBRARIES}
	${APACHEMODULE_LIBRARIES}
)

install (TARGETS mod_answer DESTINATION /usr/lib/apache2/modules COMPONENT library)
