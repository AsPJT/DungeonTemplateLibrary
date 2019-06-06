/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_PERLIN_NOISE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_PERLIN_NOISE_HPP

#include <cmath>
#include <cstdint>
#include <algorithm>
#include <array>
#include <random>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/SizeT.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace utility { //"dtl::utility"名前空間に属する

		class PerlinNoise {
		private:


			///// エイリアス (Alias) /////

			using Pint = ::std::uint_fast8_t;


			///// メンバ変数 /////

			::std::array<Pint, 512> p{ {} };


			///// メンバ関数 /////

			DTL_VERSIONING_CPP17_NODISCARD
			constexpr double getFade(const double t_) const noexcept {
				return t_ * t_* t_* (t_ * (t_ * 6 - 15) + 10);
			}

			DTL_VERSIONING_CPP17_NODISCARD
			constexpr double getLerp(const double t_, const double a_, const double b_) const noexcept {
				return a_ + t_ * (b_ - a_);
			}

			DTL_VERSIONING_CPP17_NODISCARD
			constexpr double makeGrad(const Pint hash_, const double u_, const double v_) const noexcept {
				return (((hash_ & 1) == 0) ? u_ : -u_) + (((hash_ & 2) == 0) ? v_ : -v_);
			}

			DTL_VERSIONING_CPP17_NODISCARD
			constexpr double makeGrad(const Pint hash_, const double x_, const double y_, const double z_) const noexcept {
				return this->makeGrad(hash_, hash_ < 8 ? x_ : y_, hash_ < 4 ? y_ : hash_ == 12 || hash_ == 14 ? x_ : z_);
			}

			DTL_VERSIONING_CPP17_NODISCARD
			constexpr double getGrad(const Pint hash_, const double x_, const double y_, const double z_) const noexcept {
				return this->makeGrad(hash_ & 15, x_, y_, z_);
			}

			DTL_VERSIONING_CPP17_NODISCARD
			double setNoise(double x_ = 0.0, double y_ = 0.0, double z_ = 0.0) const noexcept {
				const ::dtl::type::size x_int{ static_cast<::dtl::type::size>(static_cast<::dtl::type::size>( ::std::floor(x_)) & 255) };
				const ::dtl::type::size y_int{ static_cast<::dtl::type::size>(static_cast<::dtl::type::size>( ::std::floor(y_)) & 255) };
				const ::dtl::type::size z_int{ static_cast<::dtl::type::size>(static_cast<::dtl::type::size>( ::std::floor(z_)) & 255) };
				x_ -= ::std::floor(x_);
				y_ -= ::std::floor(y_);
				z_ -= ::std::floor(z_);
				const double u{ this->getFade(x_) };
				const double v{ this->getFade(y_) };
				const double w{ this->getFade(z_) };
				const ::dtl::type::size a0{ static_cast<::dtl::type::size>(this->p[x_int] + y_int) };
				const ::dtl::type::size a1{ static_cast<::dtl::type::size>(this->p[a0] + z_int) };
				const ::dtl::type::size a2{ static_cast<::dtl::type::size>(this->p[a0 + 1] + z_int) };
				const ::dtl::type::size b0{ static_cast<::dtl::type::size>(this->p[x_int + 1] + y_int) };
				const ::dtl::type::size b1{ static_cast<::dtl::type::size>(this->p[b0] + z_int) };
				const ::dtl::type::size b2{ static_cast<::dtl::type::size>(this->p[b0 + 1] + z_int) };

				return this->getLerp(w,
					this->getLerp(v,
						this->getLerp(u, this->getGrad(this->p[a1], x_, y_, z_), this->getGrad(this->p[b1], x_ - 1, y_, z_)),
						this->getLerp(u, this->getGrad(this->p[a2], x_, y_ - 1, z_), this->getGrad(this->p[b2], x_ - 1, y_ - 1, z_))),
					this->getLerp(v,
						this->getLerp(u, this->getGrad(this->p[a1 + 1], x_, y_, z_ - 1), this->getGrad(this->p[b1 + 1], x_ - 1, y_, z_ - 1)),
						this->getLerp(u, this->getGrad(this->p[a2 + 1], x_, y_ - 1, z_ - 1), this->getGrad(this->p[b2 + 1], x_ - 1, y_ - 1, z_ - 1))));
			}

			DTL_VERSIONING_CPP17_NODISCARD
			double setOctaveNoise(const ::std::size_t octaves_, double x_) const noexcept {
				double noise_value{};
				double amp{ 1.0 };
				for ( ::std::size_t i{}; i < octaves_; ++i) {
					noise_value += this->setNoise(x_) * amp;
					x_ *= 2.0;
					amp *= 0.5;
				}
				return noise_value;
			}

			DTL_VERSIONING_CPP17_NODISCARD
			double setOctaveNoise(const ::std::size_t octaves_, double x_, double y_) const noexcept {
				double noise_value{};
				double amp{ 1.0 };
				for ( ::std::size_t i{}; i < octaves_; ++i) {
					noise_value += this->setNoise(x_, y_) * amp;
					x_ *= 2.0;
					y_ *= 2.0;
					amp *= 0.5;
				}
				return noise_value;
			}

			DTL_VERSIONING_CPP17_NODISCARD
			double setOctaveNoise(const ::std::size_t octaves_, double x_, double y_, double z_) const noexcept {
				double noise_value{};
				double amp{ 1.0 };
				for ( ::std::size_t i{}; i < octaves_; ++i) {
					noise_value += this->setNoise(x_, y_, z_) * amp;
					x_ *= 2.0;
					y_ *= 2.0;
					z_ *= 2.0;
					amp *= 0.5;
				}
				return noise_value;
			}

		public:

			//オクターブ無しノイズを取得する
			template <typename... Args>
			DTL_VERSIONING_CPP17_NODISCARD
			double noise(const Args... args_) const noexcept {
				return this->setNoise(args_...)* 0.5 + 0.5;
			}

			//オクターブ有りノイズを取得する
			template <typename... Args>
			DTL_VERSIONING_CPP17_NODISCARD
			double octaveNoise(const ::std::size_t octaves_, const Args... args_) const noexcept {
				return this->setOctaveNoise(octaves_, args_...)* 0.5 + 0.5;
			}

			//SEED値を設定する
			void setSeed(const ::std::uint_fast32_t seed_) {
				for (::dtl::type::size i{}; i < 256; ++i)
					this->p[i] = static_cast<Pint>(i);
				::std::shuffle(this->p.begin(), this->p.begin() + 256, ::std::default_random_engine(seed_));
				for (::dtl::type::size i{}; i < 256; ++i)
					this->p[256 + i] = this->p[i];
			}


			///// コンストラクタ (Constructor) /////

			constexpr PerlinNoise() = default;
			explicit PerlinNoise(const ::std::uint_fast32_t seed_) {
				this->setSeed(seed_);
			}

		};
	}
}

#endif //Included Dungeon Template Library