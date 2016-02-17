%define libsystemd on
%define test off

Name:       argos_watchdog
Summary:    ARGOS library to detect application malfunctions
Version:    0.0.1
Release:    0
Group:      System/Libraries
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz
Source1:    %{name}.manifest
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:  cmake
%if %{?libsystemd} == on
BuildRequires: pkgconfig(libsystemd)
%endif

%description
ARGOS library to detect application malfunctions

%package devel
Summary:    ARGOS library to detect application malfunctions (Development)
Group:    System/Development
Requires: %{name} = %{version}-%{release}

%description devel
ARGOS library to detect application malfunctions (devel)

%prep
%setup -q

%build
cp %{SOURCE1} .
MAJORVER=`echo %{version} | awk 'BEGIN {FS="."}{print $1}'`

cmake . \
	-DCMAKE_INSTALL_PREFIX=%{_prefix} \
	-DFULLVER=%{version} \
	-DMAJORVER=${MAJORVER} \
	-DLIBSYSTEMD=%{libsystemd} \
	-DTEST=%{test}

make

%install
rm -rf %{buildroot}
%make_install

mkdir -p %{buildroot}%{_datadir}/license
cp LICENSE %{buildroot}%{_datadir}/license/%{name}

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%defattr(-,root,root,-)
%{_libdir}/lib%{name}.so.*
%{_datadir}/license/%{name}
%manifest %{name}.manifest

%files devel
%defattr(-,root,root,-)
%{_includedir}/%{name}/*.h
%{_libdir}/pkgconfig/%{name}.pc
%{_libdir}/lib%{name}.so
%manifest %{name}.manifest
%if %{?test} == on
%{_bindir}/argos-test
/usr/lib/systemd/system/argos-test.service
%endif
