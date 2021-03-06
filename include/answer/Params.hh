#ifndef _PARAMS_HH_
#define _PARAMS_HH_

#include <boost/lexical_cast.hpp>
#include <stdexcept>
#include <list>
#include <map>
#include <string>
#include <set>

namespace answer {

enum MinOccurs {MIN_OCCURS_0, MIN_OCCURS_1};

class Params {
public:
    virtual std::string getParam ( const std::string& paramName, MinOccurs minOcurrs = MIN_OCCURS_1 ) const = 0;
    virtual std::list<std::string> getParamList ( const std::string& paramName, MinOccurs minOcurrs = MIN_OCCURS_1 ) const = 0 ;
    virtual std::list< std::map < std::string, std::string> > getParamMapList ( const std::string& paramName, MinOccurs minOcurrs = MIN_OCCURS_1 ) const = 0;
    virtual std::map < std::string, std::string> getParamMap ( const std::string& paramName, MinOccurs minOcurrs = MIN_OCCURS_1 ) const = 0;
    virtual std::set < std::string> getParamSet ( const std::string& paramName, MinOccurs minOcurrs = MIN_OCCURS_1 ) const = 0;


    template<typename T>
    std::set < T > getParamSetByType ( const std::string& paramName, MinOccurs minOcurrs = MIN_OCCURS_1 ) const {
        std::set < T > ret;
        try {

            std::set < std::string> ss = getParamSet ( paramName, minOcurrs );
            for ( std::set < std::string>::const_iterator it = ss.begin(); it != ss.end(); ++it ) {
                ret.insert ( boost::lexical_cast<T> ( *it ) );
            }


        } catch ( std::exception &ex ) {
            throw std::runtime_error ( "Parameter type error: " +paramName );
        }

        return ret;

    }

    template<typename T>
    T getParamByType ( const std::string& paramName ) const {
        T ret;
        try {
            std::string param = getParam ( paramName );
            ret = boost::lexical_cast<T> ( param );
        } catch ( std::exception &ex ) {
            throw std::runtime_error ( "Parameter type error: " +paramName );
        }
        return ret;
    }
};

template<>
bool Params::getParamByType ( const std::string& paramName ) const;
}

#endif //_PARAMS_HH_
