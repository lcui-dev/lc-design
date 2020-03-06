add_rules("mode.debug", "mode.release")
set_warnings("all")

lcpkg_dir = "./lcpkg/installed/$(arch)-$(os)"
lcpkg_incdir = lcpkg_dir.."/include"
lcpkg_pkgdir = lcpkg_dir
if is_mode("debug") then
    lcpkg_pkgdir = lcpkg_dir.."/debug"
end
lcpkg_libdir = lcpkg_pkgdir.."/lib"
add_includedirs("include", lcpkg_incdir)
add_linkdirs(lcpkg_libdir, "/usr/local/lib", "/usr/lib")
add_defines("LCDESIGN_EXPORTS")
add_files("src/**.c")
add_headerfiles("include/(**.h)")
add_installfiles("dist/app/assets/(**)", { prefixdir = "share/assets" })

target("static")
    set_kind("static")
    set_basename("LCDesign")

target("shared")
    set_kind("shared")
    add_links("LCUI")
    set_basename("LCDesign")

includes("demo")
