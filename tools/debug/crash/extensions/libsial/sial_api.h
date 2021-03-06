/*
 * Copyright 2001 Silicon Graphics, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/* minor and major version number */
#define S_MAJOR 3
#define S_MINOR 0

#define MAX_SYMNAMELEN  100
#define MAXIDX		20

/* abi values */
#define ABI_MIPS	1
#define ABI_INTEL_X86	2
#define ABI_INTEL_IA	3
#define ABI_S390        4
#define ABI_S390X       5
#define ABI_PPC64	6
#define ABI_PPC         7

/* types of variables */
#define V_BASE          1
#define V_STRING        2
#define V_REF           3
#define V_ENUM          4
#define V_UNION         5
#define V_STRUCT        6
#define V_TYPEDEF       7
#define V_ARRAY         8

#define ENUM_S		struct enum_s
#define DEF_S		struct def_s
#define MEMBER_S	struct member_s
#define TYPE_S		struct type_s
#define VALUE_S		struct value_s
#define ARRAY_S		struct array_s
#define NODE_S		struct node_s
#define IDX_S		struct idx_s
#define VAR_S		struct var_s

ENUM_S;
DEF_S;
MEMBER_S;
TYPE_S;
VALUE_S;
ARRAY_S;
NODE_S;
IDX_S;
VAR_S;

#if linux
#include <stdint.h>
typedef uint64_t ull;
typedef uint32_t ul;
#else
typedef unsigned long long ull; 
typedef unsigned long ul;
#endif

/* THe API function calls numbers */
typedef struct {

        int (*getmem)(ull, void *, int);	/* write to system image */
        int (*putmem)(ull, void *, int);	/* read from system image */
	char* (*member)(char *, ull, TYPE_S *	/* get type and positional information ... */
		, MEMBER_S *, ull *lidx); 	/* ... about the member of a structure */
	int (*getctype)(int ctype, char *	/* get struct/union type information */
		, TYPE_S*); 
	char* (*getrtype)(ull, TYPE_S *);		/* get complex type information */
	int (*alignment)(ull);			/* get alignment value for a type */
	int (*getval)(char *, ull *);		/* get the value of a system variable */
	ENUM_S* (*getenum)(char *name);		/* get the list of symbols for an enum type */
	DEF_S*  (*getdefs)(void);		/* get the list of compiler pre-defined macros */
	uint8_t (*get_uint8)(void*);
	uint16_t (*get_uint16)(void*);
	uint32_t (*get_uint32)(void*);
	uint64_t (*get_uint64)(void*);
	char* (*findsym)(char*);
} apiops; 

/*
	Builtin API defines....
*/
/* call this function to install a new builtin 

   proto is the function prototype ex:
   struct proc* mybuiltin(int flag, char *str);

   "mybuiltin" will be the sial name for the function.
   "fp" is the pointer to the builtin function code.

*/
typedef VALUE_S* bf_t(VALUE_S*, ...);
typedef struct btspec {
	char *proto;
	bf_t *fp;
} btspec_t;

/* dso entry points */
#define BT_SPEC_TABLE   btspec_t bttlb[]
#define BT_SPEC_SYM    "bttlb"
#define BT_INIDSO_FUNC  int btinit
#define BT_INIDSO_SYM  "btinit"
#define BT_ENDDSO_FUNC  void btend
#define BT_ENDDSO_SYM  "btend"

/* maximum number of parameters that can be passed to a builtin */
#define BT_MAXARGS	20

extern apiops *sial_ops;
#define API_GETMEM(i, p, n)	((sial_ops->getmem)((i), (p), (n)))
#define API_PUTMEM(i, p, n)	((sial_ops->putmem)((i), (p), (n)))
#define API_MEMBER(n, i, tm, m, l)	((sial_ops->member)((n), (i), (tm), (m), (l)))
#define API_GETCTYPE(i, n, t)	((sial_ops->getctype)((i), (n), (t)))
#define API_GETRTYPE(i, t)	((sial_ops->getrtype)((i), (t)))
#define API_ALIGNMENT(i)	((sial_ops->alignment)((i)))
#define API_GETVAL(n, v)	((sial_ops->getval)((n), (v)))
#define API_GETENUM(n)		((sial_ops->getenum)(n))
#define API_GETDEFS()		((sial_ops->getdefs)())
#define API_GET_UINT8(ptr)	((sial_ops->get_uint8)(ptr))
#define API_GET_UINT16(ptr)	((sial_ops->get_uint16)(ptr))
#define API_GET_UINT32(ptr)	((sial_ops->get_uint32)(ptr))
#define API_GET_UINT64(ptr)	((sial_ops->get_uint64)(ptr))
#define API_FINDSYM(p)		((sial_ops->findsym)(p))

#if linux
#	if __LP64__
#		define sial_getptr(v, t) 	((t*)sial_getval(v))
#	else
#		define sial_getptr(v, t) 	((t*)(ul)sial_getval(v))
#	endif
#else
#	if (_MIPS_SZLONG == 64)
#		define sial_getptr(v, t) 	((t*)sial_getval(v))
#	else
#		define sial_getptr(v, t) 	((t*)(ul)sial_getval(v))
#	endif
#endif

/* startup function */
int	 sial_open(void);		/* initialize a session with sial */
void	 sial_apiset(apiops *, int, int, int);/* define the API for a connection */
void	 sial_setofile(void *);		/* sial should output messages to this file */
void	*sial_getofile(void);		/* where is sial currently outputing */
void	 sial_setmpath(char *p);	/* set the search path for sial scripts */
void	 sial_setipath(char *p);	/* set the search path for sial include files  */
VAR_S	*sial_builtin(char *proto, bf_t);/* install a builtin function */
int      sial_cmd(char *name, char **argv, int argc); /* execute a command w/ args */

/* load/unload of script files and directories */
ull	 sial_load(char *);		/* load/parse a file */
ull	 sial_unload(char *);		/* load/parse a file */
void	 sial_loadall(void);		/* load all files found in set path */

/* variables associated functions */
VAR_S	*sial_newvar(char *);		/* create a new static/auto variable */
void	*sial_add_globals(VAR_S*);	/* add a set of variable to the globals context */
VAR_S	*sial_newvlist(void);		/* create a root for a list of variables */

int	 sial_tryexe(char *, char**, int);/* try to execute a function */
int	 sial_parsetype(char*, TYPE_S *, int);/* parse a typedef line */
ull	 sial_exefunc(char *, VALUE_S **);/* to execute a function defined in sial */

/* help related function */
void	 sial_showallhelp(void);	/* display help info for all commands */
int	 sial_showhelp(char *);		/* display help info for a single command */

/* allocation related function */
void	*sial_alloc(int);		/* allocate some memory */
void	*sial_calloc(int);		/* allocate some 0 filed memory */
void	 sial_free(void*);		/* free it */
char	*sial_strdup(char*);		/* equivalent of strdup() returns sial_free'able char */
void	*sial_dupblock(void *p);	/* duplicate the contain of a block of allocated memory */
void	*sial_realloc(void *p, int size);	/* reallocate a block */
void	 sial_maketemp(void *p);	/* put a block on the temp list */
void	 sial_freetemp(void);		/* free the temp list */
VALUE_S	*sial_makebtype(ull);		/* create a default base type value (int) */

/* handle values */
VALUE_S	*sial_newval(void);		/* get a new placeholder for a value */
void	 sial_freeval(VALUE_S *);	/* free a value* and associated structs */
VALUE_S	*sial_makestr(char *);		/* create a string value */
ull	 sial_getval(VALUE_S*);		/* transform a random value to a ull */
VALUE_S	*sial_cloneval(VALUE_S *);	/* make a clone of a value */

/* array related */
/* add a new array element to a value */
void	 sial_addvalarray(VALUE_S*v, VALUE_S*idx, VALUE_S*val);
/* return the value associated with a int index */
VALUE_S	*sial_intindex(VALUE_S *, int);	
/* return the value associated with a 'string' index */
VALUE_S	*sial_strindex(VALUE_S *, char *);
/* set the value of an array element */
void	 sial_setarrbval(ARRAY_S*, int);	
/* get the array element coresponding to index */
ARRAY_S	*sial_getarrval(ARRAY_S**, VALUE_S*);
/* get the initiale array for a variable */
ARRAY_S	*sial_addarrelem(ARRAY_S**, VALUE_S*, VALUE_S*); 

/* type manipulation */
int sial_is_struct(int);
int sial_is_enum(int);
int sial_is_union(int);
int sial_is_typedef(int);
int sial_type_gettype(TYPE_S*t);
int sial_chkfname(char *fname, void *vfd);
int sial_loadunload(int load, char *name, int silent);

void sial_type_settype(TYPE_S*t, int type);
void sial_setcallback(void (*scb)(char *, int));
void sial_vilast(void);
void sial_vi(char *fname, int file);
void sial_type_setsize(TYPE_S*t, int size);
int sial_type_getsize(TYPE_S*t);
void sial_type_setidx(TYPE_S*t, ull idx);
ull sial_type_getidx(TYPE_S*t);
void sial_type_setidxlst(TYPE_S*t, int *idxlst);
void sial_type_setref(TYPE_S*t, int ref, int type);
void sial_type_setfct(TYPE_S*t, int val);
void sial_type_mkunion(TYPE_S*t);
void sial_type_mkenum(TYPE_S*t);
void sial_type_mkstruct(TYPE_S*t);
void sial_type_mktypedef(TYPE_S*t);
TYPE_S*sial_newtype(void);
void sial_freetype(TYPE_S*t);
TYPE_S*sial_getctype(int ctype_t, char *name, int silent);
void sial_type_free(TYPE_S* t);
void sial_pushref(TYPE_S*t, int ref);
void sial_duptype(TYPE_S*to, TYPE_S*from);
int sial_defbsize(void);
TYPE_S*sial_newbtype(int token);
void sial_setdbg(unsigned int lvl);
unsigned int sial_getdbg(void);
void sial_setname(char *name);
char *sial_getname(void);
void sial_setclass(char *class);
char **sial_getclass(void);

/* struct member functions */
void sial_member_soffset(MEMBER_S*m, int offset);
void sial_member_ssize(MEMBER_S*m, int size);
void sial_member_sfbit(MEMBER_S*m, int fbit);
void sial_member_snbits(MEMBER_S*m, int nbits);
void sial_member_sname(MEMBER_S*m, char *name);

/* enums */
ENUM_S* sial_add_enum(ENUM_S* e, char* name, int val);
/* defines */
DEF_S*	sial_add_def(DEF_S* d, char *name, char *val);

/* error handling */
/* display error w/ file/line coordinates */
/* does not return */
void sial_error(char *, ...);
/* display warning w/ file/line coordinates */
void sial_warning(char *, ...);
/* display a message and continue */
void sial_msg(char *, ...);
/* display a debug message */
#define DBG_TYPE            0x00000001
#define DBG_STRUCT          0x00000002
#define DBG_NAME            0x10000000  // 
#define DBG_ALL             0x0fffffff
void sial_dbg(int class, int level, char *, ...);
void sial_dbg_named(int class, char *name, int level, char *, ...);

/* parsers debug flags */
extern int sialdebug, sialppdebug;
