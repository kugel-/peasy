#ifndef __PEASY_TEST_H__
#define __PEASY_TEST_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define PEASY_TYPE_TEST			(peasy_test_get_type ())
#define PEASY_TEST(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_TEST, PeasyTest))
#define PEASY_TEST_CONST(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_TEST, PeasyTest const))
#define PEASY_TEST_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_TEST, PeasyTestClass))
#define PEASY_IS_TEST(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_TEST))
#define PEASY_IS_TEST_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_TEST))
#define PEASY_TEST_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_TEST, PeasyTestClass))

typedef struct _PeasyTest	PeasyTest;
typedef struct _PeasyTestClass	PeasyTestClass;

struct _PeasyTest
{
	PeasExtensionBase parent;
};

struct _PeasyTestClass
{
	PeasExtensionBaseClass parent_class;
};

GType peasy_test_get_type (void) G_GNUC_CONST;
PeasyTest *peasy_test_new (void);


G_END_DECLS

#endif /* __PEASY_TEST_H__ */
