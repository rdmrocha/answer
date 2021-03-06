#ifndef _XMLPARAMS_HH_
#define _XMLPARAMS_HH_

//This file is shared between lib and module-lib
#include <set>
#include "answer/Params.hh"
#include <libxml++/libxml++.h>
#include <axis2_msg_ctx.h>


namespace answer{

class XmlParams: public Params {
	xmlpp::DomParser _dom;
	xmlpp::Element* _rootNode;
	xmlpp::Node::NodeList _nodeList;
public:
	XmlParams(const axutil_env_t * axis_env, axiom_node_t *content_node); //For services
	XmlParams(const axutil_env_t * axis_env, struct axis2_msg_ctx * msg_ctx); //For modules
	virtual ~XmlParams();

	std::string getParam(const std::string& paramName, MinOccurs minOcurrs = MIN_OCCURS_1) const;
	std::list<std::string> getParamList(const std::string& paramName, MinOccurs minOcurrs = MIN_OCCURS_1) const;

	std::list< std::map <std::string, std::string> > getParamMapList(const std::string& paramName, MinOccurs minOcurrs = MIN_OCCURS_1) const;
	std::map <std::string, std::string> getParamMap(const std::string& paramName, MinOccurs minOcurrs = MIN_OCCURS_1) const;
	std::set <std::string> getParamSet(const std::string& paramName, MinOccurs minOcurrs = MIN_OCCURS_1) const;
};

}

#endif //_XMLPARAMS_HH_