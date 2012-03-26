#ifndef FAS_JSONRPC_METHOD_METHOD_BASE_HPP
#define FAS_JSONRPC_METHOD_METHOD_BASE_HPP

#include <stdexcept>

namespace fas{ namespace jsonrpc{

template<typename A1, typename A2 = ::fas::aspect<> >
class method_base
  : public aspect_class<A1, A2>
{
public:
  typedef aspect_class<A1, A2> super;
  typedef typename super::aspect aspect;

    /*
  typedef typename aspect::template advice_cast<_notify_>::type notify_handler_type;
  typedef typename aspect::template advice_cast<_notify_value_>::type notify_value_type;
  typedef typename aspect::template advice_cast<_notify_json_>::type notify_json_type;

  typedef typename aspect::template advice_cast<_request_>::type request_handler_type;
  typedef typename aspect::template advice_cast<_request_value_>::type request_value_type;
  typedef typename aspect::template advice_cast<_request_json_>::type request_json_type;
  typedef typename aspect::template advice_cast<_result_value_>::type result_value_type;
  typedef typename aspect::template advice_cast<_result_json_>::type result_json_type;
  */

  typedef typename aspect::template advice_cast<_context_>::type context_type;

  std::string name() const
  {
    return super::get_aspect().template get<_name_>();
  }

///-> jsonrpc interface

  /*
  template<typename R>
  bool check_name(R r) const
  {
    return super::get_aspect().template get<_name_>().check(r);
  }
  */
  
  /*
  template<typename T>
  void invoke_notify(T& t, const notify_value_type& v) 
  {
    // перекинуть в _invoke_notify(t, tm)
    super::get_aspect().template get<_notify_handler_>()(t, *this, v); 
  }
  */

  /*
  template<typename T, typename R>
  void process_notify(T& t, R r) 
  {
    super::get_aspect().template get<_parse_notify_>()(t, *this, r);
  }

  template<typename T, typename R>
  void process_request(T& t, R r, int id) 
  {
    super::get_aspect().template get<_parse_request_>()(t, *this, r, id); 
  }
  */

  template<typename T,typename M, typename V>
  void result(T& t, M& m, const V& result, int id)
  {
    super::get_aspect().template get<_send_result_>()(t, m, result, id);
  }
  
///<- jsonrpc interface

/// Для удобства 

/*
  notify_handler_type& notify_handler() 
  {
    return super::get_aspect().template get<_notify_>(); 
  }
  
  const notify_handler_type& notify_handler() const  
  {
    return super::get_aspect().template get<_notify_>();
  }
  */

  context_type& context() 
  {
    return super::get_aspect().template get<_context_>();
  }
  
  const context_type& context() const  
  {
    return super::get_aspect().template get<_context_>();
  }

};

}}

#endif