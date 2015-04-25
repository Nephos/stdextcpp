#ifndef ACCESSORS_H_
# define ACCESSORS_H_

// Usage example
// ======================
// class Name
// {
// public:
//   Name() {}
//   virtual ~Name() {}
//   create_attr(str, std::string)
// };
// ======================
// Name.get_str();
// Name.set_str("str");
// ======================

// Generate only the accessors to a attribute
# define writer_accessor(attr, type) public: virtual void set_##attr(type const & __var_arg__) { attr = __var_arg__; }
# define reader_accessor(attr, type) public: virtual type get_##attr() const { return attr; }
# define attr_accessors(attr, type) writer_accessor(attr, type) reader_accessor(attr, type)

// Should not be used out of this file
# define generate_attr(attr, type, accessible)	\
  reader_accessor(attr, type)				\
  writer_accessor(attr, type)				\
  accessible: type attr;

// Generate the attribute + the accessors
# define create_public_attr(attr, type) generate_attr(attr, type, private)
# define create_private_attr(attr, type) generate_attr(attr, type, private)
# define create_protected_attr(attr, type) generate_attr(attr, type, protected)
# define create_attr(attr, type) create_protected_attr(attr, type)

#endif /* !ACCESSORS_H_ */
