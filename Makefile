all:
	@make -C src all

install:
	cp -f usr/include/IGL.hpp $(DESTDIR)/usr/include/
	cp -Rf usr/include/igl $(DESTDIR)/usr/include/
	cp -f usr/lib/libIGL.so $(DESTDIR)/usr/lib/

clean:
	@make -C src clean
