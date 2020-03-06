add_rules("mode.debug", "mode.release")
set_warnings("all")

lcpkg_dir = "./lcpkg/installed/$(arch)-$(os)"
lcpkg_incdir = lcpkg_dir.."/include"
lcpkg_pkgdir = lcpkg_dir
if is_mode("debug") then
    lcpkg_pkgdir = lcpkg_dir.."/debug"
end
lcpkg_libdir = lcpkg_pkgdir.."/lib"
lcpkg_bindir = lcpkg_pkgdir.."/bin"
add_includedirs("include", "../include", lcpkg_incdir)
add_linkdirs(lcpkg_libdir, "/usr/local/lib", "/usr/lib")

target("demo")
    set_kind("binary")
    set_default(false)
    set_targetdir("app/")
    add_deps("shared")
    add_files("src/**.c")

    before_build(function (target)
        if val("plat") == "windows" then
            os.cp(lcpkg_bindir .. target.filename("*", "shared"), "$(scriptdir)/app/")
        end
        os.trycp("dist/app/assets/*", "$(scriptdir)/app/assets")
    end)

    if is_mode("release") then
        set_symbols("hidden")
    end

    if not is_os("windows") then
        add_rpathdirs("/usr/local/lib")
    end
