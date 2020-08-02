#include "ft_color.h"
#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST(FMT, ...)                                                                            \
	pf = asprintf(&pf_dst, FMT, ##__VA_ARGS__);                                                   \
	ft = ft_asprintf(&ft_dst, FMT, ##__VA_ARGS__);                                                \
	if (ft != pf)                                                                                 \
		ft_printf("\t%sReturn value Real(%i vs %i)Yours%s\n", COLOR(RED), pf, ft, COLOR(NORMAL)); \
	if (pf >= 0 && ft >= 0)                                                                       \
	{                                                                                             \
		if (ft_strcmp(ft_dst, pf_dst))                                                            \
			ft_printf("%s\t|%s| (Real) vs\n\t|%s| (Yours)\n%s",                                   \
			          COLOR(RED),                                                                 \
			          pf_dst,                                                                     \
			          ft_dst,                                                                     \
			          COLOR(NORMAL));                                                             \
		else                                                                                      \
		{                                                                                         \
			ft_printf("\t[%s%s%s]\n", COLOR(GREEN), ft_dst, COLOR(NORMAL));                       \
			success++;                                                                            \
		}                                                                                         \
	}                                                                                             \
	if (pf >= 0)                                                                                  \
		free(pf_dst);                                                                             \
	if (ft >= 0)                                                                                  \
		free(ft_dst);                                                                             \
	total++;

int test_printf()
{
	char* pf_dst;
	char* ft_dst;
	int   pf;
	int   ft;
	int   total   = 0;
	int   success = 0;

	ft_printf("printf {\n");
	TEST("1-Simple String.");
	TEST("2-Stringception _%s_", "Hello World");
	TEST("3-Stringception _%20s_", "Hello World");
	TEST("4-Stringception _%-20s_", "Hello World");
	TEST("5-Stringception _%20.5s_", "Hello World");
	TEST("6-Stringception _%-20.5s_", "Hello World");
	TEST("7-Stringception _%020s_", "Hello World");
	TEST("8-Stringception _%0-.20s_", "Hello World");
	TEST("9-Stringception _%.20s_", "Hello World");
	TEST("A-Stringception _%5.20s_", "Hello World");
	TEST("B-Stringception _%20.s_", "Hello World");
	TEST("C-Stringception _%-#20s_", "Hello World");
	TEST("D-Integer _%hhi_", -61234);
	TEST("E-Integer _%hhu_", -61234);
	TEST("F-Integer _%hi_", -61234);
	TEST("G-Integer _%hu_", -61234);
	TEST("H-Integer _%i_", -61234);
	TEST("I-Integer _%u_", -61234);
	TEST("J-Integer _%#.10hx_", -61234);
	TEST("K-Integer _%lX_", 0xDEADBEEF);
	TEST("L-Pointer _%p_", &pf);
	TEST("M-Pointer _%hhp_", &pf);
	TEST("N-Pointer _%hp_", &pf);
	TEST("O-Pointer _%p_", &pf);
	TEST("P-Combo _%20i_", -'*');
	TEST("Q-Combo _%20.10i_", -'*');
	TEST("R-Combo _%.10i_", -'*');
	TEST("S-Combo _%020i_", -'*');
	TEST("T-Combo _%#20.10x_", '*');
	TEST("U-Combo _%-20i_", -'*');
	TEST("V-Combo _%-20.10i_", -'*');
	TEST("W-Combo _%-.10i_", -'*');
	TEST("X-Combo _%-020i_", -'*');
	TEST("Y-Combo _%-#20.10x_", '*');
	TEST("Z-Non ASCII string _%s_", "Helloλ");
	TEST("10-NULL string _%s_", NULL);
	TEST("11-NULL string _%4s_", NULL);
	TEST("12-NULL string _%.4s_", NULL);
	TEST("13-NULL string _%S_", NULL);
	TEST("14-NULL string _%4S_", NULL);
	TEST("15-NULL string _%.4ls_", NULL);
	TEST("16-Bonus _%# -2147483648.99+08.04hi_", '*');
	TEST("17-Nothing _%20.10", 0);
	TEST("18-Nothing _%20.10__%i", 0, 42);
	TEST("19-Nothing _%20.10&_", 0);
	TEST("1A-Nothing _%20.10@_", 0);
	TEST("1B-Nothing _%20.10`_", 0);
	TEST("1C-Nothing _%20.10%_", 0);
	TEST("1D-Number _%#015X_", 0xDEADBEEF);
	TEST("1E-Zero _%+i_", 0);
	TEST("1F-Zero _%0+i_", 0);
	TEST("1G-Zero _%.0+i_", 0);
	TEST("1H-Zero _%.0+u_", 0);
	TEST("1I-Zero _%10.0i_", 0);
	TEST("1J-Zero _%10.0+u_", 0);
	TEST("1K-Zero _%-10.0+i_", 0);
	TEST("1L-Advanced _%i_%10i_%.5i_%10.5i_%010i_%.0i_", -42, -42, -42, -42, -42, 0);
	TEST("1M-Advanced _%u_%10u_%.5u_%10.5u_%010u_%.0u_", -42, -42, -42, -42, -42, 0);
	TEST("1N-Advanced _%#x_%10#x_%.5#x_%10.5#x_%010#x_%.0#x_", -42, -42, -42, -42, -42, 0);
	TEST("1O-Advanced _%#X_%10#X_%.5#X_%10.5#X_%010#X_%.0#X_", -42, -42, -42, -42, -42, 0);
	TEST("1P-Advanced _%#o_%10#o_%.5#o_%10.5#o_%010#o_%.0#o_", -42, -42, -42, -42, -42, 0);
	TEST("1Q-%", 0);
	TEST("1R-%.0z", 0);
	TEST("1S-Zero _%010.0+#o_", 0);
	TEST("1T-Advanced _%#p_%#10p_%#.5p_%#10.5p_%#010p_", -42, -42, -42, -42, -42);
	TEST("1U-Zero %#x", 0);
	TEST("1V-Zero %#.x %#.0x", 0, 0);
	TEST("1W-Wide char %C", 0x0065);
	TEST("1X-Hexa a%xb%xc%xd", 0, 55555, 1000000);
	TEST("1Y-Hexa a%Xb%Xc%Xd", 0, 55555, 1000000);
	TEST("1Z-Octal a%ob%oc%od", 0, 55555, 1000000);
	TEST("20-Octal _%o_%#o_%0o_%0#o_%.0o_%#.0o_%0.0o_%#0.0o_", 0, 0, 0, 0, 0, 0, 0, 0);
	TEST("21-Pointers _%p_%#p_%0p_%0#p_%.0p_%#.0p_%0.0p_%#0.0p_", 0, 0, 0, 0, 0, 0, 0, 0);
	TEST("22-Pointers _%p_%#p_%0p_%0#p_%.0p_%#.0p_%0.0p_%#0.0p_", -42, -42, -42, -42, -42, -42, -42, -42);
	TEST("23-Wildcard _%*s_%*s_", 5, "Hello world", 50, "Hello world");
	TEST("24-Wildcard _%.*s_%.*s_", 5, "Hello world", 50, "Hello world");
	TEST("25-Wildcard _%*.*s_%*.*s_", 5, 5, "Hello world", 50, 50, "Hello world");
	TEST("26-Wildcard _%*.*s_%*.*s_", 50, 5, "Hello world", 5, 50, "Hello world");
	TEST("27-Wildcard _%*.*s_%*.*s_", 50, -5, "Hello world", -5, 50, "Hello world");
	TEST("28-Char {%05.c}", '!');
	TEST("29-Char {%05.c}", 0);
	TEST("2A-Char {%-05.c}", '!');
	TEST("2B-Char {%05.2c}", '!');
	TEST("2C-Char {%-05.2c}", '!');

	int a, b, c, d, e, f;
	ft_printf("\t~ Flag%nWooWo% %[% 20.010-5n]%n\n", &a, &b, &c);
	printf("\t~ Flag%nWooWo% %[% 20.010-5n]%n\n", &d, &e, &f);
	if (a != d || b != e || c != f)
		ft_printf("%s\tFail: (Real,FT) (%i,%i) (%i,%i) (%i,%i)%s\n",
				  COLOR(RED), d, a, e, b, f, c, COLOR(NORMAL));
	else
		success++;
	total++;

	TEST("%s", "The End");
	ft_printf("\t%s%i / %i%s tests passed\n}\n\n",
	          (success == total ? COLOR(GREEN, BOLD) : COLOR(RED, BOLD)),
	          success,
	          total,
	          COLOR(NORMAL));
	return (success == total);
}
